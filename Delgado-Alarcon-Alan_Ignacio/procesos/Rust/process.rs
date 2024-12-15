use std::ffi::c_void;
use std::time::Duration;
use libc::{fork, getpid, nanosleep};

const MAX: i32 = 5;

fn main() {
    let ts = libc::timespec {
        tv_sec: 0,
        tv_nsec: 500_000_000, // 500ms
    };

    for _ in 1..=3 {
        unsafe {
            match fork() {
                -1 => {
                    eprintln!("ERROR");
                    std::process::exit(1);
                }
                0 => {
                    for k in (1..=MAX).rev() {
                        println!("H= {}", getpid());
                        nanosleep(&ts as *const _, std::ptr::null_mut::<c_void>());
                    }
                    std::process::exit(0);
                }
                _ => {}
            }
        }
    }
}
