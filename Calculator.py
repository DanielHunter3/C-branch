import sys


class Math:
    def __init__(self, num1, num2):
        self.x = num1
        self.y = num2

    def math_operations(self, string: str) -> float:
        match string:
            case "+":
                return self.x + self.y
            case "-":
                return self.x - self.y
            case "*":
                return self.x * self.y
            case "/":
                if self.y == 0.0:
                    sys.exit(1)
                else:
                    return self.x / self.y
            case "^":
                return self.x ** self.y
        return 0.0


def in_list(vector: list[str], string: str) -> bool:
    for i in vector:
        if i == string:
            return True
    return False


vec = ["+", "-", "*", "/", "^"]

x = float(input("Enter a first number: "))
symbal = input("Enter a math operation: ")

is_bool = in_list(vec, symbal)
if not is_bool:
    sys.exit(1)

y = float(input("Enter a second number: "))
math = Math(x, y)

print(f"Result: {math.math_operations(symbal)}")
