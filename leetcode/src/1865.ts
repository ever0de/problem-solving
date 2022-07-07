export {};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * var obj = new FindSumPairs(nums1, nums2)
 * obj.add(index,val)
 * var param_2 = obj.count(tot)
 */
class FindSumPairs {
    private counter: Map<number, number> = new Map();
    constructor(private nums1: number[], private nums2: number[]) {
        this.counter = nums2.reduce(
            (prev, curr) => prev.set(curr, (prev.get(curr) ?? 0) + 1),
            new Map<number, number>(),
        );
    }

    add(index: number, val: number): void {
        const num = this.nums2[index];
        const newNum = num + val;
        this.counter.set(num, (this.counter.get(num) ?? 0) - 1);
        this.counter.set(newNum, (this.counter.get(newNum) ?? 0) + 1);
        this.nums2[index] = newNum;
    }

    count(tot: number): number {
        return this.nums1.reduce(
            (prev, curr) => (prev += this.counter.get(tot - curr) ?? 0),
            0,
        );
    }
}

describe("1865. Finding Pairs With a Certain Sum", () => {
    const isAddFn = (method: keyof FindSumPairs): method is "add" => {
        return method === "add";
    };

    const getResult = (
        findSumPairs: FindSumPairs,
        methodParamList: [keyof FindSumPairs, number[]][],
    ): (null | number)[] => {
        const result: (null | number)[] = [null];
        for (const [method, param] of methodParamList) {
            if (isAddFn(method)) {
                findSumPairs[method](param[0], param[1]);
                result.push(null);
                continue;
            }

            result.push(findSumPairs[method](param[0]));
        }

        return result;
    };

    it(`
	new FindSumPairs([[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]])
	["count", "add", "count", "count", "add", "add", "count"]
	[    [7],[3, 2],     [8],     [4],[0, 1],[1, 1],     [7]]
	-> [null, 8, null, 2, 1, null, null, 11]	
	`, () => {
        const num1: number[] = [1, 1, 2, 2, 2, 3];
        const num2: number[] = [1, 4, 5, 2, 5, 4];
        const findSumPairs = new FindSumPairs(num1, num2);
        const methodParamList: [keyof FindSumPairs, number[]][] = [
            ["count", [7]],
            ["add", [3, 2]],
            ["count", [8]],
            ["count", [4]],
            ["add", [0, 1]],
            ["add", [1, 1]],
            ["count", [7]],
        ];

        const expected: (number | null)[] = [
            null,
            8,
            null,
            2,
            1,
            null,
            null,
            11,
        ];

        expect(getResult(findSumPairs, methodParamList)).toEqual(expected);
    });
});
