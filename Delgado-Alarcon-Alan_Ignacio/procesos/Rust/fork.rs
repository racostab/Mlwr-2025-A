use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        eprintln!("ERR: no params");
        process::exit(1);
    }

    let n: i32 = match args[1].parse() {
        Ok(num) => num,
        Err(_) => {
            eprintln!("ERR: invalid parameter");
            process::exit(1);
        }
    };

    for _ in 1..=n {
        match unsafe { libc::fork() } {
            -1 => eprintln!("ERROR"),
            _ => {}
        }
    }

    println!("{}", unsafe { libc::getpid() });
}
