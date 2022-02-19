// Number Guessing game
use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {}

fn remove_if() {
    let num = String::new();
    io::stdin().read_line(&mut num).expect("Can't read line");
    let num:u32 = match num.trim().parse() {
        Ok(num) => num,
    };
    matches {x%}
}

fn Guess_game() {
    println!("Guess a number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);
    println!("number is {}", secret_number);
    loop {
        let mut guess = String::new();
        println!("Guess: ");
        io::stdin().read_line(&mut guess).expect("Can't read line");
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(e) => {
                println!("error: {}", e);
                continue;
            }
        };
        println!("The number you guess is: {}", guess);
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
