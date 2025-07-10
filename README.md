# BufferOverflow_PortScanner

This project demonstrates foundational cybersecurity concepts through two standalone C programs: buffer overflow exploitation and TCP port scanning. It is designed for both educational and research purposes to illustrate low-level memory vulnerabilities and basic network reconnaissance techniques.

## Project Objectives

- **Security Exploitation Practice**: Demonstrates how improperly handled memory can be exploited using stack-based buffer overflows.
- **Network Scanning Fundamentals**: Implements a basic TCP port scanner using raw socket programming.
- **Comparative Analysis**: Provides a secure version (`safe.c`) of the buffer overflow program to highlight defensive programming practices.

## Key Components

| Module       | File        | Description |
|--------------|-------------|-------------|
| Vulnerable Program | `vuln.c` | Contains an intentional stack-based buffer overflow vulnerability for testing and demonstration. |
| Secure Version | `safe.c` | A patched version of the same program with proper memory handling to prevent overflows. |
| TCP Port Scanner | `scanner.c` | A standalone C tool that scans a range of TCP ports on a target IP using socket connections. |
| Makefile | `Makefile` | Compiles all components with appropriate flags. |
| Screenshots & Report | `screenshots/`, `BufferOverflow_PortScanner.pdf` | Contains annotated examples, GDB views, and terminal outputs. |

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
</details>

Build & Run Instructions
1. Compile All Binaries
bash
Copy
Edit
make
This compiles:

vuln from vuln.c

safe from safe.c

scanner from scanner.c

2. Buffer Overflow Demonstration
bash
Copy
Edit
./vuln
Follow the instructions in the PDF report to trigger and inspect the overflow using gdb.

To run the safe version:

bash
Copy
Edit
./safe
3. TCP Port Scanning
bash
Copy
Edit
./scanner <target_ip> <start_port> <end_port>
Example:

bash
Copy
Edit
./scanner 127.0.0.1 20 100
Academic Relevance
This project illustrates core system-level and security concepts relevant to:

Computer Systems: Stack memory layout, compilation, and debugging with GDB.

Cybersecurity: Common memory vulnerabilities and basic mitigation.

Computer Networks: TCP socket creation and connection attempts across port ranges.

It can serve as a foundation for further topics in exploit development, secure coding, or automated reconnaissance tooling.

Documentation
For detailed explanations, memory diagrams, terminal outputs, and screenshots, please refer to the PDF report:

📄 BufferOverflow_PortScanner.pdf
