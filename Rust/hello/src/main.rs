fn main() {
    let penguin_data = "\
    common name,length (cm)
    Little penguin,33
    Yellow-eyed penguin,65
    FiordLand penguin,60
    Invalid,data
    ";
  
    let records = penguin_data.lines();
  
    for (i, record) in records.enumerate() {
      if i == 0 || record.trim().len() == 0 {
        continue;
      }
      
      // 声明一个fields变量，类型是Vec
      // Vec是vector的缩写，是一个可伸缩的集合类型，可以认为是一个动态数组
      // <_>表示Vec中的元素类型由编译器自行推断，在很多场景下，都会帮我们省却不少功夫
      let fields: Vec<_> = record
        .split(',')
        .map(|field| field.trim())
        .collect();
      if cfg!(debug_assertions) {
          // 输出到标准错误输出
        eprintln!("debug: {:?} -> {:?}",
               record, fields);
      }
  
      let name = fields[0];
      // 1. 尝试把fields[1]的值转换为f32类型的浮点数，如果成功，则把f32值赋给length变量
      // 2. if let是一个匹配表达式，用来从=右边的结果中，匹配出length的值:
      // 当=右边的表达式执行成功，则会返回一个Ok(f32)的类型，若失败，则会返回一个Err(e)类型，if let的作用就是仅匹配Ok也就是成功的情
      // 况,如果是错误，就直接忽略，同时if let还会做一次解构匹配，通过Ok(length)去匹配右边的Ok(f32)，最终把相应的f32值赋给length
      // 3. 当然你也可以忽视成功的情况，用if let Err(e) = fields[1].parse::<f32>() {...}匹配出错误，然后打印出来，但是没啥卵用
      if let Ok(length) = fields[1].parse::<f32>() {
          // 输出到标准输出
          println!("{}, {}cm", name, length);
      }
    }
  }
 