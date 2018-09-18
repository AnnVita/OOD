import * as React from 'react';
import * as ReactDOM from 'react-dom';
import {MuiThemeProvider} from 'material-ui';

import './index.css';

import { createStore } from 'redux';
import { chartDrawerReducer } from './Controller/ChartDrawerReducers';
//import './Controller/ChartDrawerReducers.test';
import { ChartDrawerState } from './types/ChartDrawerState';

import ChartDrawerContainer from './View/ChartDrawerContainer';
import { Provider } from 'react-redux';

import Harmonic from './Model/Harmonic';
import {harmonicFunctionType} from './Model/harmonicFunctionType';

let injectTapEventPlugin = require('react-tap-event-plugin');
injectTapEventPlugin();

let harmonicsList = [] as Harmonic[];   

//harmonicsList.push(new Harmonic(4.5, 23, -1, harmonicFunctionType.Sin));
//harmonicsList.push(new Harmonic(-11, 4, 1, harmonicFunctionType.Cos));
//harmonicsList.push(new Harmonic(1, 1, 3, harmonicFunctionType.Sin));
harmonicsList.push(new Harmonic(1, 3, 1, harmonicFunctionType.Sin));
harmonicsList.push(new Harmonic(1, 3, 1, harmonicFunctionType.Sin));

const store = createStore<ChartDrawerState>(chartDrawerReducer, {
    harmonics: harmonicsList,
    selectedHarmonic: harmonicsList[0],
    tmpHarmonic: new Harmonic(0, 0, 0, harmonicFunctionType.Sin),
    selectedHarmonicIndex: 0,
    addDialogVisible: false,
    tabSelected: 'line'
});

ReactDOM.render(
    <MuiThemeProvider>
    <Provider store={store}>
        <ChartDrawerContainer />
    </Provider>
    </MuiThemeProvider>,
    document.getElementById('root') as HTMLElement
);