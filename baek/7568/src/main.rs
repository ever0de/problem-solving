use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("read line error");
    let n: i32 = input.trim().parse().expect("Parse error");
    let mut node_vec = vec![];

    for _ in 0..n {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("read line error");
        let result: Vec<i32> = input
            .trim()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();

        node_vec.push((result[0], result[1]))
    }

    for i in &node_vec {
        let mut rank = 1;
        for j in &node_vec {
            if i == j {
                continue;
            }

            if i.0 < j.0 && i.1 < j.1 {
                rank += 1;
            }
        }
        println!("{:?}", rank);
    }
}
