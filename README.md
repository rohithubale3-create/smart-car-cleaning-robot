# Smart Car Project - CCE Mysuru

This repository contains the complete Arduino source code, circuit connections, and final project report for the **Smart Car Project (CCE Mysuru)**.

---

## 📁 Repository Structure

```
smart-car-cce-mysuru/
├── motor_controller.ino               # Main Arduino control firmware
├── CIRCUIT.md                         # Detailed circuit pinout & truth table
├── README.md                          # Project documentation and guide
├── circuit/
│   └── circuit_connection.jpeg        # Circuit wiring diagram reference
└── report/
    └── final_car_report_cce_mysuru.pdf # Final Car Project Report
```

---

## 🔌 Hardware & Pinout

### L298N Motor Driver to Arduino Uno

| L298N Pin | Arduino Pin | Purpose |
| :--- | :--- | :--- |
| **ENA** | **D5** | PWM speed control for Left Motors |
| **IN1** | **D6** | Direction pin 1 (Left) |
| **IN2** | **D7** | Direction pin 2 (Left) |
| **IN3** | **D8** | Direction pin 1 (Right) |
| **IN4** | **D9** | Direction pin 2 (Right) |
| **ENB** | **D11** | PWM speed control for Right Motors |
| **Status LED** | **D13** | Activity indicator |

For full wiring guidelines and motor truth table, see [CIRCUIT.md](CIRCUIT.md).

---

## 🎮 Serial Commands

The firmware listens on the serial port at **9600 Baud Rate**:

| Command | Action |
| :---: | :--- |
| `F` | Move Forward |
| `B` | Move Backward |
| `R` | Turn Right |
| `L` | Turn Left |
| `S` | Stop all motors |
| `1` | Speed preset: **65** (~25%) |
| `2` | Speed preset: **130** (~50%) |
| `3` | Speed preset: **195** (~75%) |
| `4` | Speed preset: **255** (100% Max) |

---

## 📄 Project Report

The complete final report is available in the repository under:
- **[final_car_report_cce_mysuru.pdf](report/final_car_report_cce_mysuru.pdf)**
