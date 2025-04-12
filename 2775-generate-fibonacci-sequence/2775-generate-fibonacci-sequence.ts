function* fibGenerator(): Generator<number, any, number> {
    let a = 0, b = 1, temp = 0;
    yield a;
    yield b;
    for (let i = 0; i < 50; i++) {
        temp = a + b;
        yield temp;
        a = b;
        b = temp;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */