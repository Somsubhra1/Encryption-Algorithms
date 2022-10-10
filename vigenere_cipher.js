const tab = {
  a: "abcdefghijklmnopqrstuvwxyz",
  b: "bcdefghijklmnopqrstuvwxyza",
  c: "cdefghijklmnopqrstuvwxyzab",
  d: "defghijklmnopqrstuvwxyzabc",
  e: "efghijklmnopqrstuvwxyzabcd",
  f: "fghijklmnopqrstuvwxyzabcde",
  g: "ghijklmnopqrstuvwxyzabcdef",
  h: "hijklmnopqrstuvwxyzabcdefg",
  i: "ijklmnopqrstuvwxyzabcdefgh",
  j: "jklmnopqrstuvwxyzabcdefghi",
  k: "klmnopqrstuvwxyzabcdefghij",
  l: "lmnopqrstuvwxyzabcdefghijk",
  m: "mnopqrstuvwxyzabcdefghijkl",
  n: "nopqrstuvwxyzabcdefghijklm",
  o: "opqrstuvwxyzabcdefghijklmn",
  p: "pqrstuvwxyzabcdefghijklmno",
  q: "qrstuvwxyzabcdefghijklmnop",
  r: "rstuvwxyzabcdefghijklmnopq",
  s: "stuvwxyzabcdefghijklmnopqr",
  t: "tuvwxyzabcdefghijklmnopqrs",
  u: "uvwxyzabcdefghijklmnopqrst",
  v: "vwxyzabcdefghijklmnopqrstu",
  w: "wxyzabcdefghijklmnopqrstuv",
  x: "xyzabcdefghijklmnopqrstuvw",
  y: "yzabcdefghijklmnopqrstuvwx",
  z: "zabcdefghijklmnopqrstuvwxy",
};

const vigenereCipherCrypt = (encryptWord, key) => {
  let i,
    size = encryptWord.length,
    keySize = key.length,
    encryptedText = "",
    specialCharacterCount = 0;
  for (i = 0; i < size; i += 1) {
    let keyLetter = (i - specialCharacterCount) % keySize,
      keywordIndex = tab.a.indexOf(key[keyLetter]);
    if (tab[encryptWord[i]]) {
      encryptedText += tab[encryptWord[i]][keywordIndex];
    } else {
      encryptedText += encryptWord[i];
      specialCharacterCount++;
    }
  }
  return encryptedText;
};

vigenereCipherCrypt("steve", "abc");
