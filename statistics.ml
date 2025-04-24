(* Calculate mean using fold *)
let mean lst =
  let total, count = List.fold_left (fun (sum, n) x -> (sum + x, n + 1)) (0, 0) lst in
  float_of_int total /. float_of_int count

(* Calculate median: sort and find middle element(s) *)
let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 1 then
    float_of_int (List.nth sorted (len / 2))
  else
    let mid1 = List.nth sorted ((len - 1) / 2) in
    let mid2 = List.nth sorted (len / 2) in
    (float_of_int mid1 +. float_of_int mid2) /. 2.0

(* Count frequency using association list (immutable map-like structure) *)
let count_frequencies lst =
  List.fold_left
    (fun acc x ->
      match List.assoc_opt x acc with
      | Some count -> (x, count + 1) :: List.remove_assoc x acc
      | None -> (x, 1) :: acc)
    [] lst

(* Get modes: values with the highest frequency *)
let mode lst =
  let freqs = count_frequencies lst in
  let max_count = List.fold_left (fun acc (_, count) -> max acc count) 0 freqs in
  List.fold_right
    (fun (x, count) acc -> if count = max_count then x :: acc else acc)
    freqs []

(* Print results *)
let () =
  let data = [4; 2; 1; 3; 4; 2; 4; 2; 2; 5] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  let modes = mode data in
  Printf.printf "Mode: %s\n"
    (String.concat " " (List.map string_of_int modes))
