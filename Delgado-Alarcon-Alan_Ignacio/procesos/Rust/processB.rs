use std::process::Command;
use libc::{fork, sleep, getpid, exit};

fn hijo() {
    unsafe { sleep(2) };
    println!("quien?... te pregunto");
}

fn padre() {
    unsafe { sleep(10) };
    Command::new("ps")
        .status()
        .expect("failed to execute process");
    println!("hijos de...");
}

fn main() {
    for _ in 1..=3 {
        unsafe {
            match fork() {
                -1 => {
                    eprintln!("ERROR");
                    std::process::exit(1);
                }
                0 => {
                    // Child process
                    hijo();
                    exit(0);
                }
                _ => {
                    // Parent process
                    padre();
                }
            }
        }
    }
}
