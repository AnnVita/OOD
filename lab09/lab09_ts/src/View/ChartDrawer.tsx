import * as React from 'react';
import Harmonic from '../Model/Harmonic';
import HarmonicsCounter from '../Model/HarmonicsCounter';
import HarmonicsList from '../Controller/HarmonicsList';
import HarmonicsDetailed from '../Controller/HarmonicDetailed';
import AddHarmonicDialog from '../View/AddHarmonicDialog';
import HarmonicLineChart from '../View/HarmonicLineChart';
import HarmonicTableChart from '../View/HarmonicTableChart';
import {RaisedButton, AppBar, Paper, Tabs, Tab } from 'material-ui';
import * as style from '../View/styles';

interface ChardDrawerProps {
    harmonics: Harmonic[];
    selectedHarmonic: Harmonic;
    tmpHarmonic: Harmonic;
    selected: number;
    addDialogVisible: boolean;
    tabSelected: string;
    onSelectHarmonic: (index: number) => void;
    onAddDialogClicked: () => void;
    onDeleteClicked: (index: number) => void;
    onAddClicked: () => void;
    onCancelClicked: () => void;
    onUndoClicked: () => void;
    onRedoClicked: () => void;
    onHarmonicChange: (harmonic: Harmonic, index: number) => void;
    onTabSelected: (newValue: string) => void;
}

export default function ChartDrawer (props: ChardDrawerProps )  {

    if (props.harmonics.length === 0) {
        return (
            <Paper style={style.mainWindow} zDepth={1}>
                <AppBar
                    title="Harmonic charts"
                />
                <RaisedButton onClick={props.onAddDialogClicked} label="Add New" style={style.emptyListAdd} />
                <AddHarmonicDialog
                    onAddClicked={props.onAddClicked}
                    onCancelClicked={props.onCancelClicked}
                    visible={props.addDialogVisible}
                    tmpHarmonic={props.tmpHarmonic}
                    onHarmonicChange={props.onHarmonicChange}
                />
                <div>
                    <RaisedButton onClick={props.onUndoClicked} label="Undo" />
                    <RaisedButton onClick={props.onRedoClicked} label="Redo" />
                </div>
            </Paper>
        );
    }

    let harmonicsCounter = new HarmonicsCounter(props.harmonics);
    //let chartData = props.selectedHarmonic.getData([0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5]);
    let chartData = harmonicsCounter.getData([0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5]);

    return (
        <Paper style={style.mainWindow} zDepth={1}>
            <AppBar
                title="Harmonic charts"
            />
            <Paper style={style.harmonicList} zDepth={0}>
                <HarmonicsList
                    onSelectHarmonic={props.onSelectHarmonic}
                    harmonics={props.harmonics}
                    selectedHarmonic={props.selectedHarmonic}
                    selected={props.selected}
                />
                <div>
                    <RaisedButton onClick={props.onAddDialogClicked} label="Add New" />
                    <RaisedButton
                        onClick={() => {props.onDeleteClicked(props.selected); }}
                        label="Delete Selected"
                    />
                </div>
                <div>
                    <RaisedButton onClick={props.onUndoClicked} label="Undo" />
                    <RaisedButton onClick={props.onRedoClicked} label="Redo" />
                </div>
                <AddHarmonicDialog
                    onAddClicked={props.onAddClicked}
                    onCancelClicked={props.onCancelClicked}
                    visible={props.addDialogVisible}
                    tmpHarmonic={props.tmpHarmonic}
                    onHarmonicChange={props.onHarmonicChange}
                />
            </Paper>
            <HarmonicsDetailed
                name="show"
                harmonic={props.selectedHarmonic}
                onHarmonicChange={props.onHarmonicChange}
                index={props.selected}
            />
            <Tabs
                style={style.tabs}
                value={props.tabSelected}
                onChange={props.onTabSelected}
            >
                <Tab label="Line Chart" value="line">
                    <div style={style.chart}>
                        <HarmonicLineChart data={chartData} />
                    </div>
                </Tab>
                <Tab label="Table Chart" value="table">
                    <div style={style.chart}>
                        <HarmonicTableChart data={chartData} />
                    </div>
                </Tab>
            </Tabs>
        </Paper>
    );
}