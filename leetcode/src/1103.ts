export {};

/** We distribute some number of candies, to a row of n = num_people people in the following way:\
 * We then give 1 candy to the first person, 2 candies to the second person, and so on until we give n candies to the last person.\
 * Then, we go back to the start of the row, giving n + 1 candies to the first person, n + 2 candies to the second person, and so on until we give 2 * n candies to the last person.\
 * This process repeats (with us giving one more candy each time, and moving to the start of the row after we reach the end) until we run out of candies.  The last person will receive all of our remaining candies (not necessarily one more than the previous gift).\
 * Return an array (of length num_people and sum candies) that represents the final distribution of candies.
 **/
function distributeCandies(candies: number, num_people: number): number[] {
    const result: number[] = Array(num_people).fill(0);

    let candy: number = 1;
    let i: number = 0;
    while (candies > 0) {
        i = i % num_people;
        result[i] += candies < candy ? candies : candy;

        i++;
        candies -= candy;
        candy++;
    }

    return result;
}

describe("1103. Distribute Candies to People", () => {
    it(`candies = 7, num_people = 4 -> [1,2,3,1]`, () => {
        const candies: number = 7;
        const numPeople: number = 4;
        const expected: number[] = [1, 2, 3, 1];

        expect(distributeCandies(candies, numPeople)).toEqual(expected);
    });

    it(`candies = 10, num_people = 3 -> [5,2,3]`, () => {
        const candies: number = 10;
        const numPeople: number = 3;
        const expected: number[] = [5, 2, 3];

        expect(distributeCandies(candies, numPeople)).toEqual(expected);
    });
});
