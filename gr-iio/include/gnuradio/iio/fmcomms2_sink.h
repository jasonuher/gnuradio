/* -*- c++ -*- */
/*
 * Copyright 2014 Analog Devices Inc.
 * Author: Paul Cercueil <paul.cercueil@analog.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */


#ifndef INCLUDED_IIO_FMCOMMS2_SINK_H
#define INCLUDED_IIO_FMCOMMS2_SINK_H

#include <gnuradio/hier_block2.h>
#include <gnuradio/iio/api.h>
#include <gnuradio/sync_block.h>

#include "device_sink.h"

namespace gr {
namespace iio {

/*!
 * \brief Device specific sink for FMComms evaluation cards
 * \ingroup iio
 *
 * \details
 * This block is a sink specifically designed for FMComms2/3/4 evaluation
 * cards. However, it should support any AD936x based device using an IIO
 * driver.
 */
class IIO_API fmcomms2_sink : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<fmcomms2_sink> sptr;

    static sptr make(const std::string& uri,
                     const std::vector<bool>& ch_en,
                     unsigned long buffer_size,
                     bool cyclic);

    virtual void set_bandwidth(unsigned long bandwidth) = 0;
    virtual void set_rf_port_select(const std::string& rf_port_select) = 0;
    virtual void set_frequency(unsigned long long frequency) = 0;
    virtual void set_samplerate(unsigned long samplerate) = 0;
    virtual void set_attenuation(size_t chan, double gain) = 0;
    virtual void set_filter_params(const std::string& filter_source,
                                   const std::string& filter_filename = "",
                                   float fpass = 0.0,
                                   float fstop = 0.0) = 0;
};

} // namespace iio
} // namespace gr

#endif /* INCLUDED_IIO_FMCOMMS2_SINK_H */