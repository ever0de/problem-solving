export {};

/**
 * Given an array of integers arr, sort the array by performing a series of pancake flips.\
 * In one pancake flip we do the following steps:\
 * Choose an integer k where 1 <= k <= arr.length.\
 * Reverse the sub-array arr[0...k-1] (0-indexed).\
 * For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.\
 * Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.
 */
function pancakeSort(arr: number[]): number[] {
    return [];
}

describe("969. Pancake Sorting", () => {
    it(`[3,2,4,1] -> [4,2,4,3]`, () => {
        const input: number[] = [3, 2, 4, 1];
        const expected: number[] = [4, 2, 4, 3];

        expect(pancakeSort(input)).toEqual(expected);
    });

    it(`[1,2,3] -> []`, () => {
        const input: number[] = [1, 2, 3];
        const expected: number[] = [];

        expect(pancakeSort(input)).toEqual(expected);
    });
});
