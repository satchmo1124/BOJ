use std::io::{self, Read};
use std::collections::HashMap;

fn state(t:i32,v:Vec<i32>) {
    
}

fn main(){
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n:i32 = buf.trim().parse().unwrap();

    for _ in 0..n{
        buf.clear();
        io::stdin().read_line(&mut buf).unwrap();
        let mut v:Vec<i32> = buf.split(" ")
        .map(|x| x.trim().parse::<i32>().unwrap()).collect();
        let t = v[0];
        v = Vec::from(&v[1..]);
        state(t,v);
    }
    
}