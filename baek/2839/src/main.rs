use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("read line error");
    let n: i32 = input.trim().parse().expect("Parse error");

    let mut result = vec![];

    for i in 0..n / 5 + 1 {
        if (n - 5 * i) % 3 == 0 {
            result.push(i + (n - 5 * i) / 3);
        }
    }

    if result.is_empty() {
        println!("-1");
    } else {
        println!("{}", result.last().unwrap());
    }
}
