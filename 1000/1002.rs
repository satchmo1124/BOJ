use std::io;
struct Points{
    x:i32,
    y:i32,
    r:i32,
}

fn calculate_points(p1:Points,p2:Points) -> i32 {
    if p1.x == p2.x && p1.y == p2.y && p1.r == p2.r {
        return -1;
    }
    let rad_diff = (p1.r - p2.r) * (p1.r - p2.r);
    let rad_sum = (p1.r + p2.r) * (p1.r + p2.r);

    let dist = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);

    if rad_diff < dist && dist < rad_sum {
        2
    }
    else if rad_diff == dist || dist == rad_sum {
        1
    }
    else{
        0
    }    
}

fn main(){
    let mut buf = String::new();
    io::stdin()
    .read_line(&mut buf)
    .unwrap();

    let test_num: i32 = buf.trim().parse().unwrap();

    for _ in 0..test_num {
        let mut input = String::new();
        io::stdin()
        .read_line(&mut input)
        .unwrap();

        let v:Vec<i32>= input
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

        let jo = Points{x:v[0],y:v[1],r:v[2]};
        let baek = Points{x:v[3],y:v[4],r:v[5]};

        println!("{}",calculate_points(jo, baek));
    }
}





#[cfg(test)] 
mod tests{
    use super::*;


    #[test]
    fn test(){
        let inputs = [
            [0,0,13,40,0,37],
            [0,0,3,0,7,4],
            [1,1,1,1,1,5],
        ];
        let mut results = vec![];

        for i in 0..3 {
            let list = inputs[i];
            let p1 = Points{x:list[0],y:list[1],r:list[2]};
            let p2 = Points{x:list[3],y:list[4],r:list[5]};
            results.push(calculate_points(p1, p2))
        }
        assert_eq!([2,1,0],*results);
    }
}
