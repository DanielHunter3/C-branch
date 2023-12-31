class Maths {
    private x: number;
    private y: number;

    constructor(x: number, y: number) {
        this.x = x;
        this.y = y;
    }

    math_operations(symbal: string) {
        switch (symbal) {
            case "+": return this.x + this.y;
            case "-": return this.x - this.y;
            case "*": return this.x * this.y;
            case "/": if (this.y == 0 ) { throw new Error("На ноль делить нельзя!") } else { return this.x / this.y }
            case "^": return Math.pow(this.x, this.y);
            default: throw new Error("This is not math operation!");
        }
    }
}

import * as readline from 'readline';

const vector: string[] = ["+", "-", "*", "/", "^"]

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Please enter the first number : ', (answer1) => {
    rl.question('Enter a symbal: ', (symbal) => {
        if (in_massive(vector, symbal) == false) throw new Error("This is not math operation!")
        rl.question('Please enter the second number : ', (answer2) => {
                
            const maths = new Maths((+answer1), (+answer2))
            console.log(maths.math_operations(symbal))

            rl.close();
        })
    })
});

function in_massive(vec: string[], symbal: string): boolean {
    for (var i = 0; i < vec.length; i++) if (vec[i] == symbal) return true;
    return false;
}