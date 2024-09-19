#Part A
#use wc with -l to get the number of lines in each file
file1_lines=$(wc -l < ATaleofTwoCities.txt)
file2_lines=$(wc -l < AliceInWonderland.txt)
#add the amount of lines from each file
num_of_lines=$(($file1_lines + $file2_lines))
echo -e "There are "$num_of_lines" lines across the two files. \n"

#Part B
#use fgrep to find all the 'London' and 'Paris' in ATaleofTwoCities.txt, then use wc -w to get the number of times
num_of_london=$(fgrep -o London ATaleofTwoCities.txt | wc -w)
num_of_paris=$(fgrep -o Paris ATaleofTwoCities.txt | wc -w)
echo -e "The word \"London\" appears "$num_of_london" times and \"Paris\" appears "$num_of_paris" times in the file.\n" 

#Part C
#use egrep to search for how many vowels are in each file
file1_vowels=$(egrep -o 'a|e|i|o|u' ATaleofTwoCities.txt | wc -l)
file2_vowels=$(egrep -o 'a|e|i|o|u' AliceInWonderland.txt | wc -l)
#add the amount of vowels from each file together
num_of_vowels=$(($file1_vowels + $file2_vowels))
echo -e "There are "$num_of_vowels" vowels in the files.\n"

#use fgrep to find 'the' in each file
file1_the=$(fgrep -o the ATaleofTwoCities.txt | wc -w)
file2_the=$(fgrep -o the AliceInWonderland.txt | wc -w)
#add the amount of 'the' from each file together
num_of_the=$(($file1_the + $file2_the))
echo -e "The word \"the\" appears "$num_of_the" times in the files.\n"

#use sed to replace every instance of 'the' with 'ABC' in both files
sed -i 's/the/ABC/g' ATaleofTwoCities.txt
sed -i 's/the/ABC/g' AliceInWonderland.txt

#Part D
#use grep with '.' to get every character from each file, 
#then use sort -u to filter out duplicate characters, 
#then use tr -d '\n' to remove the line break after each character from the grep command
diff_char=$(grep -oh . ATaleofTwoCities.txt AliceInWonderland.txt | sort -u | tr -d '\n')
echo -e "Different characters used in the files: \n""$diff_char"

