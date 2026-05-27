#!/usr/bin/env bash
set -euo pipefail

# Usage:
#   ./mkcpps.sh <Class[+]>... <executable_name>
#
# Example:
#   ./mkcpps.sh Animal Tree+ jungle
# Creates (if missing):
#   main.cpp
#   Animal.cpp
#   Tree.cpp Tree.hpp
#   Makefile (NAME=jungle, SRCS=main.cpp Animal.cpp Tree.cpp, DEPS=Tree.hpp)

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 <Class[+]>... <executable_name>"
  echo "Example: $0 Animal Tree+ jungle"
  exit 1
fi

is_valid_ident() {
  [[ "$1" =~ ^[A-Za-z_][A-Za-z0-9_]*$ ]]
}

upper_guard() {
  echo "${1}_HPP" | tr '[:lower:]' '[:upper:]'
}

create_main_cpp_if_missing() {
  if [[ -e "main.cpp" ]]; then
    echo "main.cpp already exists -> skipping"
    return
  fi

  cat > "main.cpp" <<'EOF'
#include <iostream>

int main(void)
{
	std::cout << "Hello, world!" << std::endl;
	return (0);
}
EOF
  echo "Created main.cpp"
}

create_hpp_if_missing() {
  local base="$1"
  local file="${base}.hpp"
  local guard
  guard="$(upper_guard "$base")"

  if [[ -e "$file" ]]; then
    echo "$file already exists -> skipping"
    return
  fi

  cat > "$file" <<EOF
#ifndef ${guard}
# define ${guard}
# include <iostream>

class ${base}
{
	public:
		${base}(void);
		${base}(const ${base} &);
		${base} &operator=(const ${base} &);
		~${base}(void);

	private:
		int _value;
};

#endif
EOF
  echo "Created $file"
}

create_cpp_if_missing() {
  local base="$1"
  local have_hpp="$2"   # 1 if Class+ was used, else 0
  local file="${base}.cpp"

  if [[ -e "$file" ]]; then
    echo "$file already exists -> skipping"
    return
  fi

  if [[ "$have_hpp" -eq 1 ]]; then
    cat > "$file" <<EOF
#include "${base}.hpp"

${base}::${base}(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

${base}::${base}(const ${base} &${base,,})
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ${base,,};
}

${base} &${base}::operator=(const ${base} &${base,,})
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &${base,,})
		this->_value = ${base,,}._value;
	return (*this);
}

${base}::~${base}(void)
{
	std::cout << "Destructor called" << std::endl;
}
EOF
  else
    # No header requested: create a compilable placeholder translation unit.
    cat > "$file" <<EOF
#include <iostream>

static void ${base}_placeholder(void)
{
	std::cout << "${base}.cpp created (no header requested with '+')." << std::endl;
}
EOF
  fi

  echo "Created $file"
}

create_makefile_if_missing() {
  local exe_name="$1"
  shift
  local -a srcs=("$@")
  local deps_str="$DEPS_STR"

  if [[ -e "Makefile" ]]; then
    echo "Makefile already exists -> skipping"
    return
  fi

  local srcs_str=""
  for s in "${srcs[@]}"; do
    srcs_str+="${s} "
  done
  srcs_str="${srcs_str% }"

  cat > "Makefile" <<EOF
CC 		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME 	= ${exe_name}
RM		= rm -rf
SRCS 	= ${srcs_str}
DEPS	= ${deps_str}
OBJS	= \${SRCS:%.cpp=%.o}

%.o: %.cpp \${DEPS}
	@\${CC} \${CFLAGS} -c \$< -o \$@

all: \${NAME}
\${NAME} : \${OBJS}
	\${CC} \${CFLAGS} \${OBJS} -o \${NAME}
	@echo "Compiled \$(NAME)."

clean:
	\${RM} \${OBJS}
	@echo "Cleaned object files!"

fclean: clean
	\${RM} \${NAME}
	@echo "Cleaned executables!"

re: fclean all

.PHONY: clean fclean all re
EOF

  echo "Created Makefile"
}

# ---------- parse args ----------
exe_name="${!#}"
if [[ -z "$exe_name" ]]; then
  echo "Invalid executable name (empty)."
  exit 1
fi

class_tokens=("${@:1:$#-1}")

if ! is_valid_ident "$exe_name"; then
  echo "Invalid executable name: '$exe_name'"
  echo "Use a simple name like: fixed, bsp, jungle"
  exit 1
fi

create_main_cpp_if_missing

declare -a SRCS_LIST
declare -a DEPS_LIST
SRCS_LIST=("main.cpp")

for raw in "${class_tokens[@]}"; do
  want_hpp=0
  name="$raw"
  if [[ "$raw" == *"+" ]]; then
    want_hpp=1
    name="${raw%+}"
  fi

  if [[ -z "$name" ]]; then
    echo "Invalid class name: '$raw'"
    exit 1
  fi
  if ! is_valid_ident "$name"; then
    echo "Invalid class name: '$name' (from '$raw')"
    echo "Use something like: Animal, TreeNode, Fixed"
    exit 1
  fi

  if [[ $want_hpp -eq 1 ]]; then
    create_hpp_if_missing "$name"
    DEPS_LIST+=("${name}.hpp")
  fi

  create_cpp_if_missing "$name" "$want_hpp"
  SRCS_LIST+=("${name}.cpp")
done

# Build DEPS string (de-duplicate preserving order)
DEPS_STR=""
if [[ ${#DEPS_LIST[@]} -gt 0 ]]; then
  declare -A seen=()
  local_deps=()
  for d in "${DEPS_LIST[@]}"; do
    if [[ -z "${seen[$d]+x}" ]]; then
      local_deps+=("$d")
      seen[$d]=1
    fi
  done
  for d in "${local_deps[@]}"; do
    DEPS_STR+="${d} "
  done
  DEPS_STR="${DEPS_STR% }"
fi

create_makefile_if_missing "$exe_name" "${SRCS_LIST[@]}"