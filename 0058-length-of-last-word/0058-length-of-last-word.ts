function lengthOfLastWord(s: string): number {
    const temp = s.split(" ").filter(x => x !== "");
    return temp[temp.length - 1].length;
};