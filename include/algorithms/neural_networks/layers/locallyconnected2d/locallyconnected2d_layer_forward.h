/* file: locallyconnected2d_layer_forward.h */
/*******************************************************************************
* Copyright 2014-2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of the interface for the forward two-dimensional (2D) locally connected layer in the batch
//  processing mode
//--
*/

#ifndef __LOCALLYCONNECTED2D_LAYER_FORWARD_H__
#define __LOCALLYCONNECTED2D_LAYER_FORWARD_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer.h"
#include "algorithms/neural_networks/layers/locallyconnected2d/locallyconnected2d_layer_types.h"
#include "algorithms/neural_networks/layers/locallyconnected2d/locallyconnected2d_layer_forward_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace locallyconnected2d
{
namespace forward
{
namespace interface1
{
/**
 * @defgroup locallyconnected2d_forward_batch Batch
 * @ingroup locallyconnected2d_forward
 * @{
 */
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOCALLYCONNECTED2D__FORWARD__BATCHCONTAINER"></a>
 * \brief Provides methods to run implementations of the forward 2D locally connected layer.
 *        This class is associated with the daal::algorithms::neural_networks::layers::locallyconnected2d::forward::Batch class
 *        and supports the method of forward 2D locally connected layer computation in the batch processing mode
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of forward 2D locally connected layer, double or float
 * \tparam method           Computation method of the layer, \ref daal::algorithms::neural_networks::layers::locallyconnected2d::Method
 * \tparam cpu              Version of the cpu-specific implementation of the layer, \ref daal::CpuType
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType, Method method, CpuType cpu>
class BatchContainer : public layers::forward::LayerContainerIfaceImpl
{
public:
    /**
     * Constructs a container for the forward 2D locally connected layer with a specified environment
     * in the batch processing mode
     * \param[in] daalEnv   Environment object
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED BatchContainer(daal::services::Environment::env *daalEnv);
    /**
     * Default destructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED ~BatchContainer();
    /**
     * Computes the result of the forward 2D locally connected layer in the batch processing mode
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status compute() DAAL_C11_OVERRIDE;
    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status setupCompute() DAAL_C11_OVERRIDE;
    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status allocateInput() DAAL_C11_OVERRIDE
    {
        Input *input = static_cast<Input *>(_in);
        return input->allocate<algorithmFPType>(_par, (int) method);
    }
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOCALLYCONNECTED2D__FORWARD__BATCH"></a>
 * \brief Provides methods for forward 2D locally connected layer computations in the batch processing mode
 * <!-- \n<a href="DAAL-REF-LOCALLYCONNECTED2DFORWARD-ALGORITHM">Forward 2D locally connected layer description and usage models</a> -->
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of forward 2D locally connected layer, double or float
 * \tparam method           Computation method of the layer, \ref Method
 *
 * \par Enumerations
 *      - \ref Method          Computation methods for the forward 2D locally connected layer
 *      - \ref LayerDataId     Identifiers of results of the forward 2D locally connected layer
 *
 * \par References
 *      - backward::interface1::Batch class
 *
 * \DAAL_DEPRECATED
 */
template<typename algorithmFPType = DAAL_ALGORITHM_FP_TYPE, Method method = defaultDense>
class Batch : public layers::forward::LayerIfaceImpl
{
public:
    typedef layers::forward::LayerIfaceImpl super;

    typedef algorithms::neural_networks::layers::locallyconnected2d::forward::Input     InputType;
    typedef algorithms::neural_networks::layers::locallyconnected2d::Parameter          ParameterType;
    typedef algorithms::neural_networks::layers::locallyconnected2d::forward::Result    ResultType;

    ParameterType &parameter; /*!< \ref interface1::Parameter "Parameters" of the layer */
    InputType input;          /*!< %Input objects of the layer */

    /**
     * Default constructor
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Batch() : parameter(_defaultParameter)
    {
        initialize();
    };

    /**
     * Constructs a forward 2D locally connected layer in the batch processing mode
     * and initializes its parameter with the provided parameter
     * \param[in] parameter Parameter to initialize the parameter of the layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED Batch(ParameterType& parameter) : parameter(parameter), _defaultParameter(parameter)
    {
        initialize();
    };

    /**
     * Constructs forward 2D locally connected layer by copying input objects and parameters of another forward 2D locally connected layer
     * \param[in] other A layer to be used as the source to initialize the input objects
     *                  and parameters of this layer
     * \DAAL_DEPRECATED
     */
    Batch(const Batch<algorithmFPType, method> &other) : super(other),
        _defaultParameter(other.parameter), parameter(_defaultParameter), input(other.input)
    {
        initialize();
    }

    /**
    * Returns method of the layer
    * \return Method of the layer
     * \DAAL_DEPRECATED
    */
    DAAL_DEPRECATED_VIRTUAL virtual int getMethod() const DAAL_C11_OVERRIDE { return(int) method; }

    /**
     * Returns the structure that contains the input objects of the forward 2D locally connected layer
     * \return Structure that contains the input objects of the forward 2D locally connected layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual InputType *getLayerInput() DAAL_C11_OVERRIDE { return &input; }

    /**
     * Returns the structure that contains parameters of the forward 2D locally connected layer
     * \return Structure that contains parameters of the forward 2D locally connected layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual ParameterType *getLayerParameter() DAAL_C11_OVERRIDE { return &parameter; };

    /**
     * Returns the structure that contains results of 2D locally connected layer
     * \return Structure that contains results of 2D locally connected layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED layers::forward::ResultPtr getLayerResult() DAAL_C11_OVERRIDE
    {
        return getResult();
    }

    /**
     * Returns the structure that contains results of 2D locally connected layer
     * \return Structure that contains results of 2D locally connected layer
     * \DAAL_DEPRECATED
     */
    ResultPtr getResult()
    {
        return _result;
    }

    /**
     * Registers user-allocated memory to store results of 2D locally connected layer
     * \param[in] result  Structure to store results of 2D locally connected layer
     *
     * \return Status of computations
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::Status setResult(const ResultPtr& result)
    {
        DAAL_CHECK(result, services::ErrorNullResult)
        _result = result;
        _res = _result.get();
        return services::Status();
    }

    /**
     * Returns a pointer to the newly allocated 2D locally connected layer
     * with a copy of input objects and parameters of this 2D locally connected layer
     * \return Pointer to the newly allocated layer
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED services::SharedPtr<Batch<algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Batch<algorithmFPType, method> >(cloneImpl());
    }

    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status allocateResult() DAAL_C11_OVERRIDE
    {
        services::Status s = this->_result->template allocate<algorithmFPType>(&(this->input), &parameter, (int) method);
        this->_res = this->_result.get();
        return s;
    }

protected:
    /*
     * \DAAL_DEPRECATED
     */
    DAAL_DEPRECATED_VIRTUAL virtual Batch<algorithmFPType, method> *cloneImpl() const DAAL_C11_OVERRIDE
    {
        return new Batch<algorithmFPType, method>(*this);
    }

    /*
     * \DAAL_DEPRECATED
     */
    void initialize()
    {
        Analysis<batch>::_ac = new __DAAL_ALGORITHM_LAYER_CONTAINER(BatchContainer, algorithmFPType, method)(&_env);
        _in = &input;
        _par = &parameter;
        _result.reset(new ResultType());
    }

private:
    ResultPtr _result;
    ParameterType _defaultParameter;
};

/** @} */
} // namespace interface1
using interface1::BatchContainer;
using interface1::Batch;
} // namespace forward
} // namespace locallyconnected2d
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal
#endif