#use 'read' to get main string and substring from user
#save them into the 'main_s' and 'sub_s' variable
echo -n "Please enter sample input: "
read main_s
echo -n "Please enter substring: "
read sub_s

#use fgrep to match the number of times 'sub_s' occurs in 'main_s'
num_of_occur=$(fgrep -o $sub_s <<< $main_s | wc -w)
echo Number of occurences = $num_of_occur

