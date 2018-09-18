import Harmonic from './Harmonic';

export default class HarmonicCounter {
    constructor(public Harmonics: Harmonic[]) {
    }

    public getData(xValues: number[]) {
        let data: {x: number, y: number}[] = [];

        for (let x of xValues) {
            let y = 0;
            for (let i = 0; i < this.Harmonics.length; ++i) {
                y = y + this.Harmonics[i].getY(x);
                data.push({x, y});
            }
        }
        return data;
    }
}