# Dynamic Memory Management Visualizer

## Project Overview
Dynamic Memory Management Visualizer is a C-based project that demonstrates three primary memory allocation strategies: **First-Fit**, **Best-Fit**, and **Worst-Fit**. This project helps users understand how dynamic memory is allocated and managed in real-time using different algorithms.

## Features
- Supports three dynamic memory allocation algorithms:
  - First-Fit
  - Best-Fit
  - Worst-Fit
- Interactive command-line interface for input.
- Provides a visual representation of memory allocation status.
- Handles allocation failures gracefully.

## Algorithms Explained

### 1. First-Fit Algorithm
- Scans memory sequentially.
- Allocates the first available block large enough for the process.
- **Advantages:** Fast allocation.
- **Disadvantages:** May cause external fragmentation.

### 2. Best-Fit Algorithm
- Scans all memory blocks.
- Allocates the smallest block that fits the process.
- **Advantages:** Minimizes memory wastage.
- **Disadvantages:** Requires more search time.

### 3. Worst-Fit Algorithm
- Scans all memory blocks.
- Allocates the largest available block.
- **Advantages:** Leaves larger free blocks.
- **Disadvantages:** Wastes large memory segments.

## System Requirements
- GCC compiler (Linux/Windows).
- Compatible with any system supporting C programs.

## How to Run the Project

1. Ensure GCC compiler is installed.

2. Clone the repository:

    ```bash
    git clone https://github.com/Vikash-Yadav-8586/DynamicMemoryVisualizer.git
    cd DynamicMemoryVisualizer
    ```

3. Compile the program:

    ```bash
    gcc memory_visualizer.c -o memory_visualizer
    ```

4. Run the executable:

    ```bash
    ./memory_visualizer
    ```

## Input Format
- Number of memory blocks and their sizes.
- Number of processes and their sizes.
- Choose the desired allocation method.

## Sample Output
```
Enter number of memory blocks: 5
Enter sizes: 100 500 200 300 600
Enter number of processes: 3
Enter process sizes: 212 417 112
Choose Allocation Method:
1. First-Fit
2. Best-Fit
3. Worst-Fit
```

## Comparative Analysis

| Algorithm   | Time Complexity | Space Efficiency | Best Use Case                |
|-------------|-----------------|------------------|------------------------------|
| First-Fit   | O(n)            | Low              | Fast allocation, less search |
| Best-Fit    | O(n)            | High             | Minimizing memory wastage    |
| Worst-Fit   | O(n)            | Moderate         | Maximizing large partitions  |

## Future Scope
- Add a graphical user interface (GUI).
- Implement hybrid allocation strategies.
- Improve memory fragmentation handling.
- Real-time tracking of multi-threaded memory usage.

## Author
- **Name:** Vikash Yadav
- **GitHub:** [Dynamic Memory Visualizer](https://github.com/Vikash-Yadav-8586/DynamicMemoryVisualizer.git)

## License
This project is for educational purposes only.

