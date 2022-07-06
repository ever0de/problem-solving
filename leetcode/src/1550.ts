export {};

/**
 * Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 */
function threeConsecutiveOdds(arr: number[]): boolean {
    if (arr.length < 3) {
        return false;
    }

    for (let i = 0; i <= arr.length - 3; i++) {
        if (arr[i] % 2 === 1 && arr[i + 1] % 2 === 1 && arr[i + 2] % 2 === 1) {
            return true;
        }
    }

    return false;
}

describe("1550. Three Consecutive Odds", () => {
    it(`[2,6,4,1] -> false`, () => {
        const arr: number[] = [2, 6, 4, 1];
        const expected: boolean = false;

        expect(threeConsecutiveOdds(arr)).toEqual(expected);
    });

    it(`[1,2,34,3,4,5,7,23,12] -> true`, () => {
        const arr: number[] = [1, 2, 34, 3, 4, 5, 7, 23, 12];
        const expected: boolean = true;

        expect(threeConsecutiveOdds(arr)).toEqual(expected);
    });

    it(`[1,1,1] -> true`, () => {
        const arr: number[] = [1, 1, 1];
        const expected: boolean = true;

        expect(threeConsecutiveOdds(arr)).toEqual(expected);
    });
});
