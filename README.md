# 📐 Mathematical Expression Evaluator With Big Integer

This is a C++ program that evaluates mathematical expressions containing the operators `+`, `-`, `*`, `/`, and parentheses `(` and `)`. It supports **big integers** and ensures that **all operators are enclosed in parentheses**, following strict syntactic rules.

---

## 📌 Table of Contents

- [📐 Mathematical Expression Evaluator With Big Integer](#-mathematical-expression-evaluator-with-big-integer)
  - [📌 Table of Contents](#-table-of-contents)
  - [✨ Features](#-features)
  - [🚀 Usage](#-usage)
  - [🔖 Rules](#-rules)
  - [📂 Examples](#-examples)
  - [📄 License](#-license)

---

## ✨ Features

- Supports the four basic arithmetic operators: `+`, `-`, `*`, `/`
- Handles arbitrarily large integers (big integers)
- Parses and evaluates fully parenthesized expressions
- Reads input from a file and writes result to an output file

---

## 🚀 Usage

Clone the repository:

```bash
git clone https://github.com/Ducquanbm2/Lab1---My-university.git
cd Lab1---My-university
```

Compile the program:

```bash
g++ main.cpp -o main
```

Run the program with input/output files:

```bash
./main ./input.txt ./output.txt
```

> The program reads each arithmetic expression from `input.txt` line by line and writes the results to `output.txt`.

---

## 🔖 Rules

The expression must follow **strict syntactic rules**:


- ✅ Operands must be **integers only** (no decimals).
- ✅ Negative numbers must be enclosed in parentheses along with their sign.
- ✅ Parentheses must be correctly matched and nested.
- ✅ Division results are the integer quotient, rounded towards zero.
- ❌ Expressions with invalid syntax, division by zero, or unsupported characters will result in an error

> This strict syntax ensures the evaluator can parse the expression deterministically without needing precedence rules.

---

## 📂 Examples

```text
Input: (5+((8+2)*2))
Output: 25
```

```text
Input: ((6*(2+1))*(3+(3+1)))
Output: 126
```

---

## 📄 License

This project is licensed under the [GNU GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html).

© 2025 Ducquanbm2
