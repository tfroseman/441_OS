struct NumList {
    list: Vec<f32>,
    len: i32,
    min: f32,
    max: f32,
    avg: f32,
}
fn main() {
    let data = vec![0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1];

    let mut l = NumList{ list: data, len: 10, min: 0.0, max: 0.0, avg:0.0};
    l.len = 10;

    compute_stats(&mut l);

    print_nums(&l);
}

fn compute_stats(lp: &mut NumList) {
    lp.min = lp.list[0];
    lp.max = 0.0;

    for &num in lp.list.iter() {
        if num < lp.min{
            lp.min = num;
        }else if num > lp.max {
            lp.max = num;
        }
        lp.avg = lp.avg + num;
    }

    lp.avg = lp.avg / lp.len as f32;
}

fn print_nums(lp: &NumList) {
    print!("numlist::list = {{ ");
    for &variable in lp.list.iter() {
        print!("{}, ", variable);
    }

    println!("}}");
    println!("numlist::len {:?}", lp.len);
    println!("numlist::min {:?}", lp.min);
    println!("numlist::max {:?}", lp.max);
    println!("numlist::avg {:?}", lp.avg);
}
