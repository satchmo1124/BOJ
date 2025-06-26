use std::io;
use std::process;

#[derive(PartialEq,Debug)]
enum Output{
   A,
   B,
   Ans(i32),
}

fn key(v:Vec<i32>) -> Output {
   /* 길이가 2이하인 수열 예외처리 */
   if v.len() < 2 {
      return Output::A;
   }
   if v.len() == 2 {
      if v[1] == v[0] {
         return Output::Ans(v[0]);
      }
      else{
         return Output::A;
      }
   }

   /* 
   [상수 수열]
   : 완전 상수 수열 => a1 == a2 ==...(1번째 항부터 끝까지 같은 수열)
   : 불완전 상수 수열 => a1 ?= a2 == a3 ....  (2번쨰 항부터 끝까지 같은 수열)

   Proposition : 만약 a1 == a2 라면 a2 == a3 == a4... 여야 한다. 
   Proposition : 만약 a1 != a2 라면 a2 != a3 != a4... 여야 한다. ㄴㄴ
    */


   let mut diff:Vec<i32> = Vec::new();

   let is_constant = if v[1] == v[0] {true} else if v[2] == v[1] {true} else {false};

   diff.push(v[1]-v[0]);

   for i in 1..v.len()-1 {
      if (is_constant && v[i+1] != v[i]) || (!is_constant && v[i+1] == v[i]) {
         return Output::B;
      }
     diff.push(v[i+1]-v[i]);
   }

   if v[1] == v[0] && is_constant{
      // 완전 상수 수열인지 체크
      return Output::Ans(*v.last().unwrap());
   }


   /* 완전 상수 수열이 아닌 경우 (=> 모든 항이 다 같은 경우 제외 ) */
   let a = diff[1]/diff[0];
   if diff[1] % diff[0] != 0{
      return Output::B;
   }
   for i in 0..diff.len()-1{
      if a * diff[i] != diff[i+1] {
         return Output::B;
      }
   }
   let b = v[2]-a *v[1];
   let ans = a * v.last().unwrap() + b;
   
   Output::Ans(ans)
}


fn main(){
   let mut buf = String::new();
   io::stdin().read_line(&mut buf).unwrap();
   
   let n:u32 = match buf.trim().parse::<u32>(){
      Ok(n) => n,
      Err(_) => {
         process::exit(1);
      }
   };
   buf.clear();

   io::stdin().read_line(&mut buf).unwrap();
   
   let v:Vec<i32> = buf.trim().split(" ").map(|i| i.trim().parse().unwrap()).collect();

   match key(v){
      Output::A => println!("A"),
      Output::B => println!("B"),
      Output::Ans(ans) => println!("{ans}"),
   }
}

mod tests{
   use super::*;
   #[test]
   fn test(){
      assert_eq!(key(vec![1,4,13,40]),Output::Ans(121));
      assert_eq!(key(vec![1,2,3,4,5]),Output::Ans(6));
      assert_eq!(key(vec![3,6,12,24,48]),Output::Ans(96));
      assert_eq!(key(vec![0,]),Output::A);
      assert_eq!(key(vec![-1,2]),Output::A);
      assert_eq!(key(vec![57,57]),Output::Ans(57));
      assert_eq!(key(vec![16,-8,4,-2]),Output::B);
      assert_eq!(key(vec![6,5,4,3,1]),Output::B);
      assert_eq!(key(vec![1,1,2,3,4]),Output::B);
      assert_eq!(key(vec![1,4,4,4]),Output::Ans(4));
   }
}
