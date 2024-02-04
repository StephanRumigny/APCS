
from cs50 import get_string

def main():
    # get input from user
    text = get_string("Enter a sentence/paragraph: \n")

    # initialize variables to count letters, words, and sentences
    len_text = len(text)
    count_letters = 0
    count_words = 1  # Initialize to 1 to account for the first word
    count_sentences = 0

    # go through each character in input text
    for x in range(len_text):
        # Count letters
        if text[x].isalpha():
            count_letters += 1
        # count words by spaces
        if text[x] == ' ':
            count_words += 1
        # count sentences by punctuation
        if text[x] in ['.', '!', '?']:
            count_sentences += 1

    # calculate the average number of letters and sentences per 100 words
    L = (count_letters / count_words) * 100
    S = (count_sentences / count_words) * 100

    # compute reading level using Coleman-Liau formula
    reading_level = round(0.0588 * L - 0.296 * S - 15.8)

    # determine the grade level and print result
    if reading_level <= 1:
        print("Before Grade 1")
    elif reading_level >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {reading_level}")

if __name__ == "__main__":
    # calls main function
    main()
