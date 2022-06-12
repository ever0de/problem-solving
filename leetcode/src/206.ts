/**
 * Definition for singly-linked list.
 */
class ListNode {
    public readonly val: number;
    public next: ListNode | null;

    constructor(val?: number, next?: ListNode | null) {
        this.val = val === undefined ? 0 : val;
        this.next = next === undefined ? null : next;
    }

    toNumbers(): number[] {
        if (this.val === 0) {
            return [];
        }

        let current: ListNode | null = this;
        const array: number[] = [];

        while (true) {
            array.push(current.val);
            if (current.next === null) {
                break;
            }
            current = current.next;
        }

        return array;
    }
}

/**
 * Solution
 */
function reverseList(head: ListNode | null): ListNode | null {
    let prev: ListNode | null = null;

    while (head !== null) {
        const current = head;
        head = head.next;
        current.next = prev;
        prev = current;
    }

    return prev;
}

describe("206. Reverse Linked List", () => {
    const fromNumbers = (list: number[]): ListNode => {
        let root: ListNode | null = new ListNode(list.shift());
        let current: ListNode | null = root;

        while (list.length > 0) {
            const nextNode = new ListNode(list.shift());
            current.next = nextNode;
            current = nextNode;
        }

        return root;
    };

    it(`[1,2,3,4,5] -> [5,4,3,2,1]`, () => {
        const input: number[] = [1, 2, 3, 4, 5];
        const expected: number[] = [5, 4, 3, 2, 1];

        let listNode: ListNode = fromNumbers(input);
        listNode = reverseList(listNode)!;

        expect(listNode.toNumbers()).toEqual(expected);
    });

    it(`[1,2] -> [2,1]`, () => {
        const input: number[] = [1, 2];
        const expected: number[] = [2, 1];

        let listNode: ListNode = fromNumbers(input);
        listNode = reverseList(listNode)!;

        expect(listNode.toNumbers()).toEqual(expected);
    });

    it(`[] -> []`, () => {
        const input: number[] = [];
        const expected: number[] = [];

        let listNode: ListNode = fromNumbers(input);
        listNode = reverseList(listNode)!;

        expect(listNode.toNumbers()).toEqual(expected);
    });
});
