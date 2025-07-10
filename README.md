# BufferOverflow_PortScanner

This project implements two foundational cybersecurity techniques using C: buffer overflow exploitation and TCP port scanning. It is designed for educational and research purposes to demonstrate low-level memory vulnerabilities and basic network reconnaissance techniques.

## Project Objectives

The project emulates core behaviors found in system-level security and networking tools:

- **Security Exploitation Practice**: Demonstrates how stack-based buffer overflows can be exploited when memory is mishandled.
- **Network Scanning Fundamentals**: Implements a basic TCP port scanner using raw socket programming.
- **Comparative Analysis**: Offers a secure version of the vulnerable program (`safe.c`) to illustrate best practices in defensive programming.

## Key Features

### Core Components

| Module             | File                   | Description                                                                 |
|--------------------|------------------------|-----------------------------------------------------------------------------|
| Vulnerable Program | `vuln.c`               | Contains an intentional stack-based buffer overflow vulnerability.          |
| Secure Version     | `safe.c`               | A patched version with input validation to prevent memory corruption.       |
| TCP Port Scanner   | `scanner.c`            | Scans a range of TCP ports on a target IP using raw sockets.                |
| Build Script       | `Makefile`             | Compiles all three binaries: `vuln`, `safe`, and `scanner`.                 |
| Documentation      | `BufferOverflow_PortScanner.pdf` | Full technical report with explanations and screenshots.              |
| Screenshots        | `screenshots/`         | Contains GDB views, memory dumps, and sample output captures.              |

## Architecture Overview

<details>
<summary><strong>Architecture Overview</strong></summary>

```bash
BufferOverflow_PortScanner/
├── vuln.c                      # Vulnerable buffer overflow demo
├── safe.c                      # Secure version with input protection
├── scanner.c                   # TCP port scanner via socket programming
├── screenshots/                # GDB and terminal capture images
├── BufferOverflow_PortScanner.pdf  # Full write-up with explanations
├── Makefile                    # Compiler instructions
├── .gitignore
└── README.md                   # Project documentation
```
</details>

## Build & Run Instructions

### 1. Compile All Binaries

```bash
make
```

This compiles:

- `vuln` from `vuln.c`
- `safe` from `safe.c`
- `scanner` from `scanner.c`

---

### 2. Buffer Overflow Demonstration

```bash
./vuln
```

Refer to the PDF report to follow detailed steps for triggering and inspecting the overflow using `gdb`.

To run the secure version:

```bash
./safe
```

---

### 3. TCP Port Scanning

```bash
./scanner <target_ip> <start_port> <end_port>
```

**Example:**

```bash
./scanner 127.0.0.1 20 100
```

This scans ports 20–100 on localhost.

---

## Academic Relevance

This project illustrates key foundational topics across system programming and cybersecurity:

- **Computer Systems**: Understanding stack memory layout, compilation, and debugging with GDB.
- **Cybersecurity**: Demonstrates a classical memory exploit and shows mitigation with input validation.
- **Computer Networks**: Uses raw socket programming to perform TCP port enumeration.

The modular nature of this project allows for extensions into exploit development, secure coding labs, or custom scanning tools.

## Documentation

Refer to the included PDF report [`BufferOverflow_PortScanner.pdf`](BufferOverflow_PortScanner.pdf) for:

- Code walkthroughs
- Memory diagrams
- GDB outputs
- Security explanations

## Example Screenshots

All screenshots are located under the `screenshots/` directory and include:

- Pre- and post-overflow memory layouts
- GDB instruction pointer overwrite
- Safe version behavior contrast
- Terminal output from the TCP port scanner



