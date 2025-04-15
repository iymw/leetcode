type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function chunk(arr: Obj[], size: number): Obj[][] {
    let acc: Obj[][] = [];
    const arr_len = arr.length;
    for (let i = 0; i < arr_len; i += size) {
        acc.push(arr.slice(0, size));
        arr.splice(0, size);
    }
    return acc;
};
