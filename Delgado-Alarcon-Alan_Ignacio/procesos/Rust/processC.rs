fn main() {
    let args: Vec<String> = std::env::args().collect();
    let argc = args.len();
    println!("argc= {}", argc);
    if argc == 1 {
        std::process::exit(0);
    } else {
        std::process::exit(argc as i32);
    }
}
