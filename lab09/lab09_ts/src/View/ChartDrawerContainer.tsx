import ChartDrawer from '../View/ChartDrawer';
import * as actions from '../View/ChartDrawerActions';
import { ChartDrawerState } from '../types/ChartDrawerState';
import { connect, Dispatch } from 'react-redux';
import Harmonic from '../Model/Harmonic';

export function mapStateToProps({
                                    harmonics,
                                    selectedHarmonic,
                                    tmpHarmonic,
                                    selectedHarmonicIndex,
                                    addDialogVisible,
                                    tabSelected
}: ChartDrawerState) {
    return {
        harmonics,
        selectedHarmonic,
        tmpHarmonic,
        selected: selectedHarmonicIndex,
        addDialogVisible,
        tabSelected
    };
}

export function mapDispatchToProps(dispatch: Dispatch<actions.SelectHarmonic>) {
    return {
        onSelectHarmonic: (index: number) => dispatch(actions.selectHarmonic(index)),
        onAddDialogClicked: () => dispatch(actions.toggleAddDialog()),
        onAddClicked: () => dispatch(actions.addHarmonic()),
        onCancelClicked: () => dispatch(actions.toggleAddDialog()),
        onHarmonicChange: (harmonic: Harmonic, index: number) => dispatch(actions.harmonicChange(harmonic, index)),
        onDeleteClicked: (index: number) => dispatch(actions.deleteHarmonic(index)),
        onTabSelected: (newValue: string) => dispatch(actions.selectTab(newValue)),
        onUndoClicked: () => dispatch(actions.undo()),
        onRedoClicked: () => dispatch(actions.redo()),
    };
}

export default connect(mapStateToProps, mapDispatchToProps)(ChartDrawer);