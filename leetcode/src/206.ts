/**
 * Definition for singly-linked list.
 */
class ListNode {
    val: number;
    next: ListNode | null;

    constructor(val?: number, next?: ListNode | null) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }
}

function reverseList(head: ListNode | null): ListNode | null {
    return null;
}

describe("206. Reverse Linked List", () => {
    it(`[1,2,3,4,5] -> [5,4,3,2,1]`, () => {
        const input = [1, 2, 3, 4, 5];
        const expected = [5, 4, 3, 2, 1];
    });

    it(`[1,2] -> [2,1]`, () => {
        const input = [1, 2];
        const expected = [2, 1];
    });

    it(`[] -> []`, () => {
        const input = [];
        const expected = [];
    });
});
