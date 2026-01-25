*This project has been created as part of the 42 curriculum by rafasant.*

# NetPractice

## Description
**NetPractice** is a practical networking exercise from the 42 curriculum designed to introduce the fundamentals of **TCP/IP addressing** and basic **network configuration**.  
The project consists of solving **10 small network levels** in a browser-based interface by correctly configuring:
- **IPv4 addresses**
- **Subnet masks (CIDR)**
- **Default gateways**
- (when applicable) **routes** between networks

Each level provides one or more goals (e.g., "Host A can reach Host B"). The objective is to modify the **unshaded fields** until the network becomes functional.

By completing the project, you develop intuition for:
- how a subnet mask defines a network and a host range
- when traffic is local vs routed through a gateway
- how routers and interfaces separate networks
- basic routing decisions needed for multi-network reachability

---

## Instructions

### 1) Run the training interface
1. Download and extract the NetPractice files (as provided on the intra).
2. Open the project folder:
   - `NetPractice/net_practice/`
3. Open `index.html` in your web browser.

### 2) Choose a mode
- **Practice mode**: enter your 42 login in the input field to generate your personal configuration.
- **Evaluation mode**: uses randomized configurations similar to peer-evaluation.

### 3) Solve each level
For each level:
1. Read the goals displayed at the top of the page.
2. Modify only the **unshaded (editable)** fields.
3. Click **[Check again]** to validate the configuration.
4. Use the logs at the bottom to diagnose issues (invalid IP, missing gateway, wrong mask, etc.).

### 4) Export and submit
After successfully completing a level:
1. Click **[Get my config]** to export your configuration file.
2. Save the exported file.
3. Repeat for all 10 levels.

**Submission requirement (mandatory):**
- You must submit **10 exported configuration files** (one per level) at the **root of your Git repository**.
- Only the files present in your repository will be evaluated during the defense.

---

## Networking Concepts Covered
This project requires understanding and applying the following concepts:

### TCP/IP Addressing
- IPv4 format: `A.B.C.D`
- Network part vs host part (defined by the subnet mask)

### Subnet Mask / CIDR
- How masks define the network boundary (e.g., `/24`, `/26`, `/30`)
- How to compute:
  - network address
  - broadcast address
  - usable host range
- Recognizing subnet increments ("block size" method) for masks like `/25–/30`

### Default Gateway
- Why a gateway is required when a destination is outside the local subnet
- Gateway must be reachable on the local subnet

### Routers and Switches
- Switches operate at Layer 2 and do not create new IP networks
- Routers operate at Layer 3 and separate networks:
  - each router interface belongs to a different subnet
  - routers forward packets between networks if routes exist

### OSI Layers (high-level)
- Layer 2 (Data Link): switching / MAC-based delivery on a LAN
- Layer 3 (Network): IP addressing, routing, gateways

---

## Resources
The following references were used to study the theory necessary to solve NetPractice levels:

- 42 Cursus Guide (NetPractice Theory):  
  https://42-cursus.gitbook.io/guide/4-rank-04/netpractice/theory

- GitHub: lpaube/NetPractice (explanations and examples):  
  https://github.com/lpaube/NetPractice?tab=readme-ov-file#ip-address-network-layer

- Medium article (networking overview):  
  https://ismailassil.medium.com/networking-726246dd2177

### How AI was used
AI assistance was used strictly as a learning and documentation aid:
- To generate **step-by-step explanations** of subnet masks, CIDR notation, default gateways, and basic routing concepts.
- To create **practice exercises with solutions** (e.g., calculating network/broadcast addresses and usable IP ranges for various masks) to improve speed and confidence without relying on external tools.
- To draft and format this **README.md**, ensuring it matches the project's subject requirements (instructions, submission requirements, and a proper resources section).

All generated content was reviewed to ensure it is understood and can be explained during peer-evaluation.

---