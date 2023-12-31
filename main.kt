import kotlin.math.pow

class Math(private val x: Double, private val y: Double) {
    fun mathOperations(symbol: String): Double {
        return when (symbol) {
            "+" -> x + y
            "-" -> x - y
            "*" -> x * y
            "/" -> {
                if (y == 0.0) {
                    println("The Y is 0")
                    abort()
                } else {
                    x / y
                }
            }
            "^" -> x.pow(y)
            else -> {
                println("This is not math operation: $symbol")
                abort()
            }
        }
    }
}

fun inVector(vec: List<String>, symbol: String): Pair<String, Boolean> {
    for (i in vec) {
        if (i == symbol) {
            return Pair(symbol, true)
        }
    }
    return Pair("", false)
}

fun main() {
    var x = 0.0
    var y = 0.0
    var symbol: String
    val vec = listOf("+", "-", "*", "/", "^")
    print("Enter a first number: ")
    x = readLine()!!.toDouble()
    print("Enter a math symbol: ")
    symbol = readLine()!!
    var result = ""
    var isBool = false
    val (res, bool) = inVector(vec, symbol)
    result = res
    isBool = bool
    if (!isBool) {
        println("This is not math operation: $symbol")
        abort()
    }
    print("Enter a second number: ")
    y = readLine()!!.toDouble()
    val math = Math(x, y)
    println("Result: ${math.mathOperations(result)}")
}
