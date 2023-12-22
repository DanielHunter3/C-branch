package main

import (
	"fmt"
	"math"
	"os"
)

type Math struct { // ГДЕ ООП?
	x float64
	y float64
}

func (object Math) math_operation(symbal string) float64 {
	switch symbal {
	case "+":
		return object.x + object.y
	case "-":
		return object.x - object.y
	case "*":
		return object.x * object.y
	case "/":
		if object.y == 0.0 {
			os.Exit(1)
		} else {
			return object.x / object.y
		}
	case "^":
		return math.Pow(object.x, object.y)
	default:
		os.Exit(1)
	}

	return 0.0
}

func main() {
	var x, y float64
	var symbal string
	vec := []string{"+", "-", "*", "/", "^"}

	fmt.Print("Enter a first number: ")
	fmt.Scan(&x)

	fmt.Print("Enter a math operation: ")
	fmt.Scan(&symbal)

	var result, is_bool = in_vector(vec, symbal)
	if is_bool == false {
		fmt.Println("This is not math operation: ", symbal)
		os.Exit(0)
	}

	fmt.Print("Enter a second number: ")
	fmt.Scan(&y)

	res := Math{x: x, y: y}
	fmt.Println("Result: ", res.math_operation(result))
}

func in_vector(array []string, symbal string) (string, bool) {
	for _, value := range array {
		if value == symbal {
			return value, true
		}
	}
	return "", false
}
