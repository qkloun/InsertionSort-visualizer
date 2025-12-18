# Insertion Sort Visualizer
A real-time visualization of the Insertion Sort algorithm built with C++ and SDL2. This project provides an interactive, step-by-step graphical demonstration of how insertion sort organizes data, making it perfect for students and developers learning about sorting algorithms.

This project visualizes the Insertion Sort algorithm in real time, showing how data is recursively partitioned and sorted. Built in C++ with the SDL2 library, it provides a step-by-step graphical demonstration aimed at making sorting algorithms easier to understand for students and developers.

## Features
🎯 **Visual Algorithm Learning** - See how insertion sort works step-by-step<br>
🌈 **Color-Coded Visualization** - Different colors for current element, comparison element, and sorted bars<br>
📊 **Real-time Animation** - Smooth animations showing element movements<br>
🎲 **Random Data Generation** - Creates 100 random numbers (1-99) for each run<br>
📈 **Descending Order Sort** - Sorts from largest to smallest<br>
⏱️ **Adjustable Speed** - Configurable animation delay for better visualization<br>
🖥️ **Cross-Platform** - Works on Windows, macOS, and Linux<br>

## Algorithm Breakdown
The visualization demonstrates the key phases of Insertion Sort:
1. 🎯 **Element Selection** - Pick the current element to insert into the sorted portion
2. 🔍 **Backward Comparison** - Compare the selected element with sorted elements from right to left
3. ➡️ **Element Shifting** - Shift larger elements one position to the right to make space (animated movement)
4. 📌 **Insertion** - Place the element in its correct position within the sorted portion
5. 🔁 **Iteration** - Repeat for each element until the entire array is sorted

### The visualizer displays this process in real-time with color coding:
- **Blue bars** - Unsorted elements
- **Red bar** - Current element being inserted
- **Yellow bar** - Element being compared
- **Green bars** - Sorted portion of the array

## InsertionSort Time Complexity
- Best Case: **O(n)** - When the array is already sorted
- Average Case: **O(n²)** - Random order
- Worst Case: **O(n²)** - When the array is reverse sorted

## Technologies Used
- **C++**
- **SLD2**
- **CMake** (optional, for build automation)

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Watch the inspiration video!
Watch the algorithm in action! This visualization is inspired by educational sorting algorithm demonstrations.

<a href="https://www.youtube.com/watch?v=kPRA0W1kECg" target="_blank">
  <img src="https://img.youtube.com/vi/kPRA0W1kECg/maxresdefault.jpg" width="400"/></a>


&copy; 2025 GitHub &bull; [Code of Conduct](https://www.contributor-covenant.org/version/2/1/code_of_conduct/code_of_conduct.md)
