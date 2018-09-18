import Harmonic from '../Model/Harmonic';

export interface ChartDrawerState {
    harmonics: Harmonic[];
    selectedHarmonic: Harmonic;
    tmpHarmonic: Harmonic;
    selectedHarmonicIndex: number;
    addDialogVisible: boolean;
    tabSelected: string;
}