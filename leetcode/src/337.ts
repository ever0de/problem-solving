export {};

/**
 * Definition for a binary tree node.
 */
class TreeNode {
    public readonly val: number;
    public left: TreeNode | null;
    public right: TreeNode | null;

    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = val === undefined ? 0 : val;
        this.left = left === undefined ? null : left;
        this.right = right === undefined ? null : right;
    }
}

/**
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.\
 * Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.\
 * Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
 */
function rob(root: TreeNode | null): number {
    const res = sub(root);
    return Math.max(res[0], res[1]);
}

function sub(root: TreeNode | null): [number, number] {
    if (root === null) {
        return [0, 0];
    }

    const left = sub(root.left);
    const right = sub(root.right);

    return [
        Math.max(left[0], left[1]) + Math.max(right[0], right[1]),
        root.val + left[0] + right[0],
    ];
}

describe("337. House Robber III", () => {
    //     const fromNullableNumbers = (
    //         root: TreeNode,
    //         list: (null | number)[],
    //     ): TreeNode | null => {
    //         if (list.length === 0) {
    //             return null;
    //         }
    //         root.left = new TreeNode(list.shift() ?? undefined);
    //         root.right = new TreeNode(list.shift() ?? undefined);
    //         if (root.left && root.right) {
    //             return fromNullableNumbers(root.left, list);
    //         }
    //         if (!root.right) {
    //             return fromNullableNumbers(root.right, list);
    //         }
    //         return (
    //             fromNullableNumbers(root.left, list) ??
    //             fromNullableNumbers(root.right, list)
    //         );
    //     };

    it(`[3,2,3,null,3,null,1] -> 7`, () => {
        const input: (null | number)[] = [3, 2, 3, null, 3, null, 1];
        const expected = 7;

        // const rootNode = new TreeNode(input.shift() ?? undefined);
        // fromNullableNumbers(rootNode, input);
        // expect(rob(rootNode)).toBe(expected);
    });

    it(`[3,4,5,1,3,null,1] -> 9`, () => {
        const input: (null | number)[] = [3, 4, 5, 1, 3, null, 1];
        const expected = 9;

        //         const rootNode = new TreeNode(input.shift() ?? undefined);
        //         fromNullableNumbers(rootNode, input);
        //         expect(rob(rootNode)).toBe(expected);
    });

    it(`[null] -> 0`, () => {
        const input: null[] = [null];
        const expected = 0;

        //         const rootNode = new TreeNode(input.shift() ?? undefined);
        //         fromNullableNumbers(rootNode, input);
        //         expect(rob(rootNode)).toBe(expected);
    });
});
