export {};

/** Given an integer array nums and an integer k, return the kth largest element in the array.\
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 **/
function findKthLargest(nums: number[], k: number): number {
    return nums.sort((a, b) => b - a)[k - 1];
}

describe("215. Kth Largest Element in an Array", () => {
    it(`[3,2,1,5,6,4], k = 2 -> 5`, () => {
        const input: number[] = [3, 2, 1, 5, 6, 4];
        const k: number = 2;
        const expected: number = 5;

        expect(findKthLargest(input, k)).toEqual(expected);
    });

    it(`[3,2,3,1,2,4,5,5,6], k = 4 -> 4`, () => {
        const input: number[] = [3, 2, 3, 1, 2, 4, 5, 5, 6];
        const k: number = 4;
        const expected: number = 4;

        expect(findKthLargest(input, k)).toEqual(expected);
    });

    it(`[3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6], k = 2 -> 10`, () => {
        const input: number[] = [
            3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2,
            4, 7, 8, 5, 6,
        ];
        const k: number = 2;
        const expected: number = 10;

        expect(findKthLargest(input, k)).toEqual(expected);
    });
});
