mod mathematics {
    pub struct Math {
        x: f64,
        y: f64
    }

    impl Math {
        pub fn create(x: f64, y: f64) -> Math { Math { x, y } }
        pub fn result_of_operations(&self, symbal: String) -> f64 {
            match symbal.as_str() {
                "+" => self.x + self.y,
                "-" => self.x - self.y,
                "*" => self.x * self.y,
                "/" => { if self.y == 0.0 { panic!("The Y is 0") } else { self.x / self.y } }
                "^" => f64::powf(self.x, self.y),
                _ => panic!("This is not math operation: {symbal}")
            }
        }
    }
}

fn main() {
    let vec = vec!["+", "-", "*", "/", "^"];
    let (mut scanner, mut scanner2, mut scanner3) =
        (String::new(), String::new(), String::new());

    println!("Enter a first number: ");
    std::io::stdin().read_line(&mut scanner).unwrap();
    let x: f64 = scanner.trim().parse().unwrap();

    println!("Enter a math operation: ");
    std::io::stdin().read_line(&mut scanner2).unwrap();
    let symbal: String = scanner2.trim().parse().unwrap();

    let (result, is_bool) = math_operations(vec, symbal.as_str());
    if is_bool == false {panic!("This is not math operation: {symbal}")}

    println!("Enter a second number: ");
    std::io::stdin().read_line(&mut scanner3).unwrap();
    let y: f64 = scanner3.trim().parse().unwrap();

    let math = mathematics::Math::create(x, y);

    println!("Result: {}", math.result_of_operations(result))
}

fn math_operations(vec: Vec<&str>, symbal: &str) -> (String, bool) {
    for i in vec { if i == symbal { return (symbal.to_string(), true); } }
    ("".to_string(), false)
}