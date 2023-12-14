# MlqCPUSheduling
A C++ implementation of a Multilevel Queue (MLQ) CPU scheduling simulation can be found in this repository. Through time-based priority promotion, the simulation shows how a simple MLQ scheduler may be used to manage tasks at various priority levels and prevent CPU exhaustion. 

## Table of Contents

- [Overview](#overview)
- [Key Features](#key-features)
- [Implementation Details](#implementation-details)
- [How to Use](#how-to-use)
- [Contributing](#contributing)
- [License](#license)

## Overview

CPU scheduling is a critical aspect of operating systems, determining the order in which processes are executed. Multilevel Queue scheduling involves dividing the ready queue into several separate queues, each with its own priority. This simulation showcases a basic MLQ scheduler that handles process execution across different priority levels.

## Key Features

- **Multilevel Queue Implementation**: Processes are assigned to different priority queues based on their priority levels.
- **Time-Based Priority Promotion**: Processes waiting too long in lower-priority queues are promoted to higher-priority queues to prevent starvation.
- **Simple Simulation**: The simulation demonstrates how processes are executed based on their priority levels and arrival times.

## Implementation Details

The implementation utilizes C++ and provides a `MultilevelQueue` class that encapsulates the logic for queue management, process enqueueing/dequeueing, and simulation of CPU scheduling.

## How to Use

To use this simulation:
1. Clone the repository locally.
2. Compile and run the `main.cpp` file, which demonstrates the CPU scheduling simulation with example processes.

```bash
g++ main.cpp -o scheduler
./scheduler
