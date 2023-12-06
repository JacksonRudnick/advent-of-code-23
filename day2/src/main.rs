use std::fs;
use std::collections::HashMap;

fn process_line(line: &str) -> i32 {
	let mut min: HashMap<&str, i32> = HashMap::new();
	let mut num = 0;
	let mut pnum = 0;

	let nline = line.replace(&[':', ';', ','][..], "");

	for x in nline.split_whitespace() {
		let mut t = x.parse::<i32>();

		if t.is_ok() {num = t.unwrap()}
		else if num != 0 {
			let (lead, _) = x.split_at(x.len());
			println!("{} {}", lead, num);
			pnum = min.insert(lead, num).unwrap_or(i32::from(0));
			if pnum > num { min.insert(lead, pnum); }
		}
	}

	println!("{} * {} * {}", *min.get("red").unwrap_or(&i32::from(1)), *min.get("blue").unwrap_or(&i32::from(1)), *min.get("green").unwrap_or(&i32::from(1)));

	return *min.get("red").unwrap_or(&i32::from(1)) * *min.get("blue").unwrap_or(&i32::from(1)) * *min.get("green").unwrap_or(&i32::from(1));
}

fn main() {
	let mut sum: i32 = 0;

	for line in fs::read_to_string("src/input.txt").unwrap().lines() {
		sum += process_line(line);
	}
	

	println!("{}", sum);
}
