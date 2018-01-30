/* Copyright (c) 2013-2016, EPFL/Blue Brain Project
 *                          Daniel Nachbaur <daniel.nachbaur@epfl.ch>
 *
 * This file is part of Brion <https://github.com/BlueBrain/Brion>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/** @file brion/enums.h Enumerations used in Brion. */

#ifndef BRION_ENUMS
#define BRION_ENUMS

#include <ostream>

namespace brion
{
namespace enums
{
/** The supported sections in a BlueConfig file. */
enum BlueConfigSection
{
    CONFIGSECTION_RUN = 0,
    CONFIGSECTION_CONNECTION,
    CONFIGSECTION_PROJECTION,
    CONFIGSECTION_REPORT,
    CONFIGSECTION_STIMULUS,
    CONFIGSECTION_STIMULUSINJECT,
    CONFIGSECTION_UNKNOWN,
    CONFIGSECTION_ALL //!< @internal must be last
};

/** The supported structural mesh types. */
enum MeshStructure
{
    MESH_SPINES = 0, //!< spines
    MESH_BOUTONS,    //!< boutons
    MESH_PSD,        //!< post-synaptic densities
    MESH_AZ,         //!< active zones
    MESH_ENDO,       //!< endoplasmic reticulum
    MESH_ALL         //!< @internal must be last
};

/** The supported formats for mesh files. */
enum MeshFormat
{
    MESHFORMAT_BINARY,
    MESHFORMAT_HDF5
};

/** The supported versions for mesh files. */
enum MeshVersion
{
    MESH_VERSION_1 = 1,
    MESH_VERSION_2 = 2
};

/** The supported attributes of a neuron. */
enum NeuronAttributes
{
    NEURON_MORPHOLOGY_NAME = 1 << 0,
    NEURON_MORPHOLOGY_ORIGIN = 1 << 1,
    NEURON_COLUMN_GID = 1 << 2,
    NEURON_MINICOLUMN_GID = 1 << 3,
    NEURON_LAYER = 1 << 4,
    NEURON_MTYPE = 1 << 5,
    NEURON_ETYPE = 1 << 6,
    NEURON_POSITION_X = 1 << 7,
    NEURON_POSITION_Y = 1 << 8,
    NEURON_POSITION_Z = 1 << 9,
    NEURON_ROTATION = 1 << 10,
    NEURON_METYPE = 1 << 11,
    NEURON_ALL = 12,

    NEURON_ALL_ATTRIBUTES = (1 << NEURON_ALL) - 1
};

/** The supported classifications for a neuron. */
enum NeuronClass
{
    NEURONCLASS_MTYPE = 0,            //!< L2PC, L5CSPC, ...
    NEURONCLASS_MORPHOLOGY_CLASS = 1, //!< PYR, INT
    NEURONCLASS_FUNCTION_CLASS = 2,   //!< EXC, INH
    NEURONCLASS_ETYPE,                //!< cAD, dAL, ...
    NEURONCLASS_INVALID
};

/** The supported target types. */
enum TargetType
{
    TARGET_CELL = 0,
    TARGET_COMPARTMENT,
    TARGET_ALL //!< @internal must be last
};


/** The supported attributes of a synapse. */
enum SynapseAttributes
{
    SYNAPSE_CONNECTED_NEURON = 1 << 0,
    SYNAPSE_DELAY = 1 << 1,
    SYNAPSE_POSTSYNAPTIC_SECTION = 1 << 2,
    SYNAPSE_POSTSYNAPTIC_SEGMENT = 1 << 3,
    SYNAPSE_POSTSYNAPTIC_SEGMENT_DISTANCE = 1 << 4,
    SYNAPSE_PRESYNAPTIC_SECTION = 1 << 5,
    SYNAPSE_PRESYNAPTIC_SEGMENT = 1 << 6,
    SYNAPSE_PRESYNAPTIC_SEGMENT_DISTANCE = 1 << 7,
    SYNAPSE_CONDUCTANCE = 1 << 8,
    SYNAPSE_UTILIZATION = 1 << 9,
    SYNAPSE_DEPRESSION = 1 << 10,
    SYNAPSE_FACILITATION = 1 << 11,
    SYNAPSE_DECAY = 1 << 12,
    SYNAPSE_TYPE = 1 << 13,
    SYNAPSE_PRESYNAPTIC_MTYPE = 1 << 14,
    SYNAPSE_DENDRITE_BRANCHORDER = 1 << 15,
    SYNAPSE_AXON_BRANCHORDER = 1 << 16,
    SYNAPSE_ABSOLUTE_SYNAPTIC_EFFICACY = 1 << 17,
    SYNAPSE_POSTSYNAPTIC_BRANCH_TYPE = 1 << 18,
    SYNAPSE_NO_ATTRIBUTES = 1 << 19,
    SYNAPSE_ALL = 19,

    SYNAPSE_DYNAMICS_CONSTANTS = SYNAPSE_CONDUCTANCE | SYNAPSE_UTILIZATION |
                                 SYNAPSE_DEPRESSION | SYNAPSE_FACILITATION |
                                 SYNAPSE_DELAY | SYNAPSE_DECAY |
                                 SYNAPSE_ABSOLUTE_SYNAPTIC_EFFICACY,

    SYNAPSE_PRESYNAPTIC_NEURON = SYNAPSE_PRESYNAPTIC_SECTION |
                                 SYNAPSE_PRESYNAPTIC_SEGMENT |
                                 SYNAPSE_PRESYNAPTIC_SEGMENT_DISTANCE,

    SYNAPSE_POSTSYNAPTIC_NEURON = SYNAPSE_POSTSYNAPTIC_SECTION |
                                  SYNAPSE_POSTSYNAPTIC_SEGMENT |
                                  SYNAPSE_POSTSYNAPTIC_SEGMENT_DISTANCE,

    SYNAPSE_ALL_ATTRIBUTES =
        SYNAPSE_CONNECTED_NEURON | SYNAPSE_TYPE | SYNAPSE_PRESYNAPTIC_MTYPE |
        SYNAPSE_DENDRITE_BRANCHORDER | SYNAPSE_AXON_BRANCHORDER |
        SYNAPSE_POSTSYNAPTIC_BRANCH_TYPE | SYNAPSE_DYNAMICS_CONSTANTS |
        SYNAPSE_PRESYNAPTIC_NEURON | SYNAPSE_POSTSYNAPTIC_NEURON
};

/** The positions of a synapse. */
enum SynapsePositions
{
    SYNAPSE_PRESYNAPTIC_SURFACE_X = 1 << 1,
    SYNAPSE_PRESYNAPTIC_SURFACE_Y = 1 << 2,
    SYNAPSE_PRESYNAPTIC_SURFACE_Z = 1 << 3,
    SYNAPSE_POSTSYNAPTIC_SURFACE_X = 1 << 4,
    SYNAPSE_POSTSYNAPTIC_SURFACE_Y = 1 << 5,
    SYNAPSE_POSTSYNAPTIC_SURFACE_Z = 1 << 6,
    SYNAPSE_PRESYNAPTIC_CENTER_X = 1 << 7,
    SYNAPSE_PRESYNAPTIC_CENTER_Y = 1 << 8,
    SYNAPSE_PRESYNAPTIC_CENTER_Z = 1 << 9,
    SYNAPSE_POSTSYNAPTIC_CENTER_X = 1 << 10,
    SYNAPSE_POSTSYNAPTIC_CENTER_Y = 1 << 11,
    SYNAPSE_POSTSYNAPTIC_CENTER_Z = 1 << 12,
    SYNAPSE_POSITION_NO_ATTRIBUTES = 1 << 13,
    SYNAPSE_POSITION_ALL = 13,

    SYNAPSE_PRESYNAPTIC_POSITION =
        SYNAPSE_PRESYNAPTIC_SURFACE_X | SYNAPSE_PRESYNAPTIC_SURFACE_Y |
        SYNAPSE_PRESYNAPTIC_SURFACE_Z | SYNAPSE_PRESYNAPTIC_CENTER_X |
        SYNAPSE_PRESYNAPTIC_CENTER_Y | SYNAPSE_PRESYNAPTIC_CENTER_Z,

    SYNAPSE_POSTSYNAPTIC_POSITION =
        SYNAPSE_POSTSYNAPTIC_SURFACE_X | SYNAPSE_POSTSYNAPTIC_SURFACE_Y |
        SYNAPSE_POSTSYNAPTIC_SURFACE_Z | SYNAPSE_POSTSYNAPTIC_CENTER_X |
        SYNAPSE_POSTSYNAPTIC_CENTER_Y | SYNAPSE_POSTSYNAPTIC_CENTER_Z,

    SYNAPSE_POSITION = SYNAPSE_CONNECTED_NEURON | SYNAPSE_PRESYNAPTIC_POSITION |
                       SYNAPSE_POSTSYNAPTIC_POSITION
};

enum SynapseOldPositions
{
    SYNAPSE_OLD_PRESYNAPTIC_CENTER_X = 1 << 1,
    SYNAPSE_OLD_PRESYNAPTIC_CENTER_Y = 1 << 2,
    SYNAPSE_OLD_PRESYNAPTIC_CENTER_Z = 1 << 3,
    SYNAPSE_OLD_POSTSYNAPTIC_CENTER_X = 1 << 4,
    SYNAPSE_OLD_POSTSYNAPTIC_CENTER_Y = 1 << 5,
    SYNAPSE_OLD_POSTSYNAPTIC_CENTER_Z = 1 << 6,
    SYNAPSE_OLD_POSITION_ALL = 7,

    SYNAPSE_OLD_PRESYNAPTIC_POSITION = SYNAPSE_OLD_PRESYNAPTIC_CENTER_X |
                                       SYNAPSE_OLD_PRESYNAPTIC_CENTER_Y |
                                       SYNAPSE_OLD_PRESYNAPTIC_CENTER_Z,

    SYNAPSE_OLD_POSTSYNAPTIC_POSITION = SYNAPSE_OLD_POSTSYNAPTIC_CENTER_X |
                                        SYNAPSE_OLD_POSTSYNAPTIC_CENTER_Y |
                                        SYNAPSE_OLD_POSTSYNAPTIC_CENTER_Z,

    SYNAPSE_OLD_POSITION = SYNAPSE_CONNECTED_NEURON |
                           SYNAPSE_OLD_PRESYNAPTIC_POSITION |
                           SYNAPSE_OLD_POSTSYNAPTIC_POSITION
};

}
}

#endif
