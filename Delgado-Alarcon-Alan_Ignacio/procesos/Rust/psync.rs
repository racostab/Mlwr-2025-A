use std::fs::{OpenOptions, File};
use std::io::{BufRead, BufReader, Write};
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

fn proceso(pid: usize, counter: Arc<Mutex<i32>>) {
    loop {
        let mut lock = counter.lock().unwrap();
        let mut file_read = BufReader::new(File::open("contador.txt").unwrap());
        let mut line = String::new();
        file_read.read_line(&mut line).unwrap();
        *lock = line.trim().parse().unwrap();
        
        println!("{}<Value R: {}, PID: {:?}>", "\t\t".repeat(pid), *lock, std::process::id());
        *lock += 1;
        thread::sleep(Duration::from_secs(1));
        
        let mut file_write = OpenOptions::new().write(true).truncate(true).open("contador.txt").unwrap();
        writeln!(file_write, "{}", *lock).unwrap();
        println!("{}<Value W: {}, PID: {:?}>", "\t\t".repeat(pid), *lock, std::process::id());
    }
}

fn main() {
    let args: Vec<String> = std::env::args().collect();
    if args.len() != 2 {
        eprintln!("ERR: no params");
        std::process::exit(1);
    }

    let n: usize = args[1].parse().unwrap();
    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];

    for i in 0..n {
        let counter = Arc::clone(&counter);
        let handle = thread::spawn(move || {
            proceso(i, counter);
        });
        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap();
    }
}
