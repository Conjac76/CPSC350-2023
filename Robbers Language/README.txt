This trasnlates english to the robbers language. Every consonant (spelling matters, not
pronunciation) is doubled, and an o is inserted in between. Vowels are left intact.
“stubborn” translates to Robber Language as sostotubobboborornon.
It contains 3 classes Model, Translator, and FileProcessor. Model has a default
constructor/destructor and two methods: 

  - translateSingleConsonant– takes a single consonant character as input and returns a
    string representing its encoding in Rövarspråket. Capitalization should be preserved.
  
  - translateSingleVowel – takes a single vowel character as input and returns a string
    representing its encoding in Rövarspråket. Capitalization should be preserved.
  
Translator has a Default Constructor/Destructor and two methods:

  - translateEnglishWord – takes a single string representing a single English word as input
    and returns a string representing the Rövarspråket translation.

  - translateEnglishSentence – takes a single string representing a single English sentence
    as input and returns a string representing the Rövarspråket translation. Make sure to
    account for punctuation.
  
 FileProcessor has a default construcotr/destructor and a method:
 
  - processFile – takes a string representing the input file  (English) and a string
    representing the output file (where the Rövarspråket translation will be written). This
    method has a void return type. The method should produce an HTML file that has the
    original English text in bold followed by an empty line, followed by the Rövarspråket
    translation in italics. If you are not familiar with HTML, a simple tutorial is available here: