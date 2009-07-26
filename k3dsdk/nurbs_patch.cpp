// K-3D
// Copyright (c) 1995-2008, Timothy M. Shead
//
// Contact: tshead@k-3d.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#include "metadata_keys.h"
#include "nurbs_patch.h"
#include "primitive_validation.h"
#include "selection.h"
#include "string_cast.h"

#include <numeric>

namespace k3d
{

namespace nurbs_patch
{

/////////////////////////////////////////////////////////////////////////////////////////////
// const_primitive

const_primitive::const_primitive(
	const mesh::indices_t& PatchFirstPoints,
	const mesh::counts_t& PatchUPointCounts,
	const mesh::counts_t& PatchVPointCounts,
	const mesh::orders_t& PatchUOrders,
	const mesh::orders_t& PatchVOrders,
	const mesh::indices_t& PatchUFirstKnots,
	const mesh::indices_t& PatchVFirstKnots,
	const mesh::selection_t& PatchSelections,
	const mesh::materials_t& PatchMaterials,
	const mesh::indices_t& PatchPoints,
	const mesh::weights_t& PatchPointWeights,
	const mesh::knots_t& PatchUKnots,
	const mesh::knots_t& PatchVKnots,
	const mesh::indices_t& PatchFirstTrimLoops,
	const mesh::counts_t& PatchTrimLoopCounts,
	const mesh::indices_t& TrimLoopFirstCurves,
	const mesh::counts_t& TrimLoopCurveCounts,
	const mesh::selection_t& TrimLoopSelections,
	const mesh::indices_t& CurveFirstPoints,
	const mesh::counts_t& CurvePointCounts,
	const mesh::orders_t& CurveOrders,
	const mesh::indices_t& CurveFirstKnots,
	const mesh::selection_t& CurveSelections,
	const mesh::indices_t& CurvePoints,
	const mesh::weights_t& CurvePointWeights,
	const mesh::knots_t& CurveKnots,
	const mesh::points_2d_t& Points,
	const mesh::selection_t& PointSelections,
	const mesh::table_t& ConstantAttributes,
	const mesh::table_t& UniformAttributes,
	const mesh::table_t& VaryingAttributes,
	const mesh::table_t& VertexAttributes
		) :
	patch_first_points(PatchFirstPoints),
	patch_u_point_counts(PatchUPointCounts),
	patch_v_point_counts(PatchVPointCounts),
	patch_u_orders(PatchUOrders),
	patch_v_orders(PatchVOrders),
	patch_u_first_knots(PatchUFirstKnots),
	patch_v_first_knots(PatchVFirstKnots),
	patch_selections(PatchSelections),
	patch_materials(PatchMaterials),
	patch_points(PatchPoints),
	patch_point_weights(PatchPointWeights),
	patch_u_knots(PatchUKnots),
	patch_v_knots(PatchVKnots),
	patch_first_trim_loops(PatchFirstTrimLoops),
	patch_trim_loop_counts(PatchTrimLoopCounts),
	trim_loop_first_curves(TrimLoopFirstCurves),
	trim_loop_curve_counts(TrimLoopCurveCounts),
	trim_loop_selections(TrimLoopSelections),
	curve_first_points(CurveFirstPoints),
	curve_point_counts(CurvePointCounts),
	curve_orders(CurveOrders),
	curve_first_knots(CurveFirstKnots),
	curve_selections(CurveSelections),
	curve_points(CurvePoints),
	curve_point_weights(CurvePointWeights),
	curve_knots(CurveKnots),
	points(Points),
	point_selections(PointSelections),
	constant_attributes(ConstantAttributes),
	uniform_attributes(UniformAttributes),
	varying_attributes(VaryingAttributes),
	vertex_attributes(VertexAttributes)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////
// primitive

primitive::primitive(
	mesh::indices_t& PatchFirstPoints,
	mesh::counts_t& PatchUPointCounts,
	mesh::counts_t& PatchVPointCounts,
	mesh::orders_t& PatchUOrders,
	mesh::orders_t& PatchVOrders,
	mesh::indices_t& PatchUFirstKnots,
	mesh::indices_t& PatchVFirstKnots,
	mesh::selection_t& PatchSelections,
	mesh::materials_t& PatchMaterials,
	mesh::indices_t& PatchPoints,
	mesh::weights_t& PatchPointWeights,
	mesh::knots_t& PatchUKnots,
	mesh::knots_t& PatchVKnots,
	mesh::indices_t& PatchFirstTrimLoops,
	mesh::counts_t& PatchTrimLoopCounts,
	mesh::indices_t& TrimLoopFirstCurves,
	mesh::counts_t& TrimLoopCurveCounts,
	mesh::selection_t& TrimLoopSelections,
	mesh::indices_t& CurveFirstPoints,
	mesh::counts_t& CurvePointCounts,
	mesh::orders_t& CurveOrders,
	mesh::indices_t& CurveFirstKnots,
	mesh::selection_t& CurveSelections,
	mesh::indices_t& CurvePoints,
	mesh::weights_t& CurvePointWeights,
	mesh::knots_t& CurveKnots,
	mesh::points_2d_t& Points,
	mesh::selection_t& PointSelections,
	mesh::table_t& ConstantAttributes,
	mesh::table_t& UniformAttributes,
	mesh::table_t& VaryingAttributes,
	mesh::table_t& VertexAttributes
		) :
	patch_first_points(PatchFirstPoints),
	patch_u_point_counts(PatchUPointCounts),
	patch_v_point_counts(PatchVPointCounts),
	patch_u_orders(PatchUOrders),
	patch_v_orders(PatchVOrders),
	patch_u_first_knots(PatchUFirstKnots),
	patch_v_first_knots(PatchVFirstKnots),
	patch_selections(PatchSelections),
	patch_materials(PatchMaterials),
	patch_points(PatchPoints),
	patch_point_weights(PatchPointWeights),
	patch_u_knots(PatchUKnots),
	patch_v_knots(PatchVKnots),
	patch_first_trim_loops(PatchFirstTrimLoops),
	patch_trim_loop_counts(PatchTrimLoopCounts),
	trim_loop_first_curves(TrimLoopFirstCurves),
	trim_loop_curve_counts(TrimLoopCurveCounts),
	trim_loop_selections(TrimLoopSelections),
	curve_first_points(CurveFirstPoints),
	curve_point_counts(CurvePointCounts),
	curve_orders(CurveOrders),
	curve_first_knots(CurveFirstKnots),
	curve_selections(CurveSelections),
	curve_points(CurvePoints),
	curve_point_weights(CurvePointWeights),
	curve_knots(CurveKnots),
	points(Points),
	point_selections(PointSelections),
	constant_attributes(ConstantAttributes),
	uniform_attributes(UniformAttributes),
	varying_attributes(VaryingAttributes),
	vertex_attributes(VertexAttributes)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////
// create

primitive* create(mesh& Mesh)
{
	mesh::primitive& generic_primitive = Mesh.primitives.create("nurbs_patch");

	primitive* const result = new primitive(
		generic_primitive.structure["uniform"].create<mesh::indices_t>("patch_first_points"),
		generic_primitive.structure["uniform"].create<mesh::counts_t>("patch_u_point_counts"),
		generic_primitive.structure["uniform"].create<mesh::counts_t>("patch_v_point_counts"),
		generic_primitive.structure["uniform"].create<mesh::orders_t>("patch_u_orders"),
		generic_primitive.structure["uniform"].create<mesh::orders_t>("patch_v_orders"),
		generic_primitive.structure["uniform"].create<mesh::indices_t>("patch_u_first_knots"),
		generic_primitive.structure["uniform"].create<mesh::indices_t>("patch_v_first_knots"),
		generic_primitive.structure["uniform"].create<mesh::selection_t>("patch_selections"),
		generic_primitive.structure["uniform"].create<mesh::materials_t>("patch_materials"),
		generic_primitive.structure["vertex"].create<mesh::indices_t>("patch_points"),
		generic_primitive.structure["vertex"].create<mesh::weights_t>("patch_point_weights"),
		generic_primitive.structure["u_knot"].create<mesh::knots_t>("patch_u_knots"),
		generic_primitive.structure["v_knot"].create<mesh::knots_t>("patch_v_knots"),
		generic_primitive.structure["uniform"].create<mesh::indices_t>("patch_first_trim_loops"),
		generic_primitive.structure["uniform"].create<mesh::counts_t>("patch_trim_loop_counts"),
		generic_primitive.structure["trim_loop"].create<mesh::indices_t>("trim_loop_first_curves"),
		generic_primitive.structure["trim_loop"].create<mesh::counts_t>("trim_loop_curve_counts"),
		generic_primitive.structure["trim_loop"].create<mesh::selection_t>("trim_loop_selections"),
		generic_primitive.structure["trim_uniform"].create<mesh::indices_t>("curve_first_points"),
		generic_primitive.structure["trim_uniform"].create<mesh::counts_t>("curve_point_counts"),
		generic_primitive.structure["trim_uniform"].create<mesh::orders_t>("curve_orders"),
		generic_primitive.structure["trim_uniform"].create<mesh::indices_t>("curve_first_knots"),
		generic_primitive.structure["trim_uniform"].create<mesh::selection_t>("curve_selections"),
		generic_primitive.structure["trim_vertex"].create<mesh::indices_t>("curve_points"),
		generic_primitive.structure["trim_vertex"].create<mesh::weights_t>("curve_point_weights"),
		generic_primitive.structure["trim_knot"].create<mesh::knots_t>("curve_knots"),
		generic_primitive.structure["trim_point"].create<mesh::points_2d_t>("points"),
		generic_primitive.structure["trim_point"].create<mesh::selection_t>("point_selections"),
		generic_primitive.attributes["constant"],
		generic_primitive.attributes["uniform"],
		generic_primitive.attributes["varying"],
		generic_primitive.attributes["vertex"]
		);

	result->patch_selections.set_metadata_value(metadata::key::role(), metadata::value::selection_role());
	result->patch_points.set_metadata_value(metadata::key::domain(), metadata::value::mesh_point_indices_domain());

	return result;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// validate

const_primitive* validate(const mesh::primitive& Primitive)
{
	if(Primitive.type != "nurbs_patch")
		return 0;

	try
	{
		require_valid_primitive(Primitive);

		const mesh::table_t& uniform_structure = require_structure(Primitive, "uniform");
		const mesh::table_t& vertex_structure = require_structure(Primitive, "vertex");
		const mesh::table_t& u_knot_structure = require_structure(Primitive, "u_knot");
		const mesh::table_t& v_knot_structure = require_structure(Primitive, "v_knot");
		const mesh::table_t& trim_loop_structure = require_structure(Primitive, "trim_loop");
		const mesh::table_t& trim_uniform_structure = require_structure(Primitive, "trim_uniform");
		const mesh::table_t& trim_vertex_structure = require_structure(Primitive, "trim_vertex");
		const mesh::table_t& trim_knot_structure = require_structure(Primitive, "trim_knot");
		const mesh::table_t& trim_point_structure = require_structure(Primitive, "trim_point");

		const mesh::table_t& constant_attributes = require_attributes(Primitive, "constant");
		const mesh::table_t& uniform_attributes = require_attributes(Primitive, "uniform");
		const mesh::table_t& varying_attributes = require_attributes(Primitive, "varying");
		const mesh::table_t& vertex_attributes = require_attributes(Primitive, "vertex");

		const mesh::indices_t& patch_first_points = require_array<mesh::indices_t>(Primitive, uniform_structure, "patch_first_points");
		const mesh::counts_t& patch_u_point_counts = require_array<mesh::counts_t>(Primitive, uniform_structure, "patch_u_point_counts");
		const mesh::counts_t& patch_v_point_counts = require_array<mesh::counts_t>(Primitive, uniform_structure, "patch_v_point_counts");
		const mesh::orders_t& patch_u_orders = require_array<mesh::orders_t>(Primitive, uniform_structure, "patch_u_orders");
		const mesh::orders_t& patch_v_orders = require_array<mesh::orders_t>(Primitive, uniform_structure, "patch_v_orders");
		const mesh::indices_t& patch_u_first_knots = require_array<mesh::indices_t>(Primitive, uniform_structure, "patch_u_first_knots");
		const mesh::indices_t& patch_v_first_knots = require_array<mesh::indices_t>(Primitive, uniform_structure, "patch_v_first_knots");
		const mesh::selection_t& patch_selections = require_array<mesh::selection_t>(Primitive, uniform_structure, "patch_selections");
		const mesh::materials_t& patch_materials = require_array<mesh::materials_t>(Primitive, uniform_structure, "patch_materials");
		const mesh::indices_t& patch_points = require_array<mesh::indices_t>(Primitive, vertex_structure, "patch_points");
		const mesh::weights_t& patch_point_weights = require_array<mesh::weights_t>(Primitive, vertex_structure, "patch_point_weights");
		const mesh::knots_t& patch_u_knots = require_array<mesh::knots_t>(Primitive, u_knot_structure, "patch_u_knots");
		const mesh::knots_t& patch_v_knots = require_array<mesh::knots_t>(Primitive, v_knot_structure, "patch_v_knots");
		const mesh::indices_t& patch_first_trim_loops = require_array<mesh::indices_t>(Primitive, uniform_structure, "patch_first_trim_loops");
		const mesh::counts_t& patch_trim_loop_counts = require_array<mesh::counts_t>(Primitive, uniform_structure, "patch_trim_loop_counts");
		const mesh::indices_t& trim_loop_first_curves = require_array<mesh::indices_t>(Primitive, trim_loop_structure, "trim_loop_first_curves");
		const mesh::counts_t& trim_loop_curve_counts = require_array<mesh::counts_t>(Primitive, trim_loop_structure, "trim_loop_curve_counts");
		const mesh::selection_t& trim_loop_selections = require_array<mesh::selection_t>(Primitive, trim_loop_structure, "trim_loop_selections");
		const mesh::indices_t& curve_first_points = require_array<mesh::indices_t>(Primitive, trim_uniform_structure, "curve_first_points");
		const mesh::counts_t& curve_point_counts = require_array<mesh::counts_t>(Primitive, trim_uniform_structure, "curve_point_counts");
		const mesh::orders_t& curve_orders = require_array<mesh::orders_t>(Primitive, trim_uniform_structure, "curve_orders");
		const mesh::indices_t& curve_first_knots = require_array<mesh::indices_t>(Primitive, trim_uniform_structure, "curve_first_knots");
		const mesh::selection_t& curve_selections = require_array<mesh::selection_t>(Primitive, trim_uniform_structure, "curve_selections");
		const mesh::indices_t& curve_points = require_array<mesh::indices_t>(Primitive, trim_vertex_structure, "curve_points");
		const mesh::weights_t& curve_point_weights = require_array<mesh::weights_t>(Primitive, trim_vertex_structure, "curve_point_weights");
		const mesh::knots_t& curve_knots = require_array<mesh::knots_t>(Primitive, trim_knot_structure, "curve_knots");
		const mesh::points_2d_t& points = require_array<mesh::points_2d_t>(Primitive, trim_point_structure, "points");
		const mesh::selection_t& point_selections = require_array<mesh::selection_t>(Primitive, trim_point_structure, "point_selections");

		require_metadata(Primitive, patch_selections, "patch_selections", metadata::key::role(), metadata::value::selection_role());
		require_metadata(Primitive, patch_points, "patch_points", metadata::key::domain(), metadata::value::mesh_point_indices_domain());

		require_table_row_count(Primitive, u_knot_structure, "u_knot",
			std::accumulate(patch_u_point_counts.begin(), patch_u_point_counts.end(), 0)
			+ std::accumulate(patch_u_orders.begin(), patch_u_orders.end(), 0));
		require_table_row_count(Primitive, v_knot_structure, "v_knot",
			std::accumulate(patch_v_point_counts.begin(), patch_v_point_counts.end(), 0)
			+ std::accumulate(patch_v_orders.begin(), patch_v_orders.end(), 0));

		require_table_row_count(Primitive, constant_attributes, "constant", 1);
		require_table_row_count(Primitive, uniform_attributes, "uniform", uniform_structure.row_count());
		/** \todo Compute the varying attribute size */
		//require_table_row_count(Primitive, varying_attributes, "varying", );
		require_table_row_count(Primitive, vertex_attributes, "vertex", vertex_structure.row_count());

	return new const_primitive(
		patch_first_points,
		patch_u_point_counts,
		patch_v_point_counts,
		patch_u_orders,
		patch_v_orders,
		patch_u_first_knots,
		patch_v_first_knots,
		patch_selections,
		patch_materials,
		patch_points,
		patch_point_weights,
		patch_u_knots,
		patch_v_knots,
		patch_first_trim_loops,
		patch_trim_loop_counts,
		trim_loop_first_curves,
		trim_loop_curve_counts,
		trim_loop_selections,
		curve_first_points,
		curve_point_counts,
		curve_orders,
		curve_first_knots,
		curve_selections,
		curve_points,
		curve_point_weights,
		curve_knots,
		points,
		point_selections,
		constant_attributes,
		uniform_attributes,
		varying_attributes,
		vertex_attributes);
	}
	catch(std::exception& e)
	{
		log() << error << e.what() << std::endl;
	}

	return 0;
}

primitive* validate(mesh::primitive& Primitive)
{
	if(Primitive.type != "nurbs_patch")
		return 0;

	try
	{
		require_valid_primitive(Primitive);

		mesh::table_t& uniform_structure = require_structure(Primitive, "uniform");
		mesh::table_t& vertex_structure = require_structure(Primitive, "vertex");
		mesh::table_t& u_knot_structure = require_structure(Primitive, "u_knot");
		mesh::table_t& v_knot_structure = require_structure(Primitive, "v_knot");
		mesh::table_t& trim_loop_structure = require_structure(Primitive, "trim_loop");
		mesh::table_t& trim_uniform_structure = require_structure(Primitive, "trim_uniform");
		mesh::table_t& trim_vertex_structure = require_structure(Primitive, "trim_vertex");
		mesh::table_t& trim_knot_structure = require_structure(Primitive, "trim_knot");
		mesh::table_t& trim_point_structure = require_structure(Primitive, "trim_point");

		mesh::table_t& constant_attributes = require_attributes(Primitive, "constant");
		mesh::table_t& uniform_attributes = require_attributes(Primitive, "uniform");
		mesh::table_t& varying_attributes = require_attributes(Primitive, "varying");
		mesh::table_t& vertex_attributes = require_attributes(Primitive, "vertex");

		mesh::indices_t& patch_first_points = require_array<mesh::indices_t>(Primitive, uniform_structure, "patch_first_points");
		mesh::counts_t& patch_u_point_counts = require_array<mesh::counts_t>(Primitive, uniform_structure, "patch_u_point_counts");
		mesh::counts_t& patch_v_point_counts = require_array<mesh::counts_t>(Primitive, uniform_structure, "patch_v_point_counts");
		mesh::orders_t& patch_u_orders = require_array<mesh::orders_t>(Primitive, uniform_structure, "patch_u_orders");
		mesh::orders_t& patch_v_orders = require_array<mesh::orders_t>(Primitive, uniform_structure, "patch_v_orders");
		mesh::indices_t& patch_u_first_knots = require_array<mesh::indices_t>(Primitive, uniform_structure, "patch_u_first_knots");
		mesh::indices_t& patch_v_first_knots = require_array<mesh::indices_t>(Primitive, uniform_structure, "patch_v_first_knots");
		mesh::selection_t& patch_selections = require_array<mesh::selection_t>(Primitive, uniform_structure, "patch_selections");
		mesh::materials_t& patch_materials = require_array<mesh::materials_t>(Primitive, uniform_structure, "patch_materials");
		mesh::indices_t& patch_points = require_array<mesh::indices_t>(Primitive, vertex_structure, "patch_points");
		mesh::weights_t& patch_point_weights = require_array<mesh::weights_t>(Primitive, vertex_structure, "patch_point_weights");
		mesh::knots_t& patch_u_knots = require_array<mesh::knots_t>(Primitive, u_knot_structure, "patch_u_knots");
		mesh::knots_t& patch_v_knots = require_array<mesh::knots_t>(Primitive, v_knot_structure, "patch_v_knots");
		mesh::indices_t& patch_first_trim_loops = require_array<mesh::indices_t>(Primitive, uniform_structure, "patch_first_trim_loops");
		mesh::counts_t& patch_trim_loop_counts = require_array<mesh::counts_t>(Primitive, uniform_structure, "patch_trim_loop_counts");
		mesh::indices_t& trim_loop_first_curves = require_array<mesh::indices_t>(Primitive, trim_loop_structure, "trim_loop_first_curves");
		mesh::counts_t& trim_loop_curve_counts = require_array<mesh::counts_t>(Primitive, trim_loop_structure, "trim_loop_curve_counts");
		mesh::selection_t& trim_loop_selections = require_array<mesh::selection_t>(Primitive, trim_loop_structure, "trim_loop_selections");
		mesh::indices_t& curve_first_points = require_array<mesh::indices_t>(Primitive, trim_uniform_structure, "curve_first_points");
		mesh::counts_t& curve_point_counts = require_array<mesh::counts_t>(Primitive, trim_uniform_structure, "curve_point_counts");
		mesh::orders_t& curve_orders = require_array<mesh::orders_t>(Primitive, trim_uniform_structure, "curve_orders");
		mesh::indices_t& curve_first_knots = require_array<mesh::indices_t>(Primitive, trim_uniform_structure, "curve_first_knots");
		mesh::selection_t& curve_selections = require_array<mesh::selection_t>(Primitive, trim_uniform_structure, "curve_selections");
		mesh::indices_t& curve_points = require_array<mesh::indices_t>(Primitive, trim_vertex_structure, "curve_points");
		mesh::weights_t& curve_point_weights = require_array<mesh::weights_t>(Primitive, trim_vertex_structure, "curve_point_weights");
		mesh::knots_t& curve_knots = require_array<mesh::knots_t>(Primitive, trim_knot_structure, "curve_knots");
		mesh::points_2d_t& points = require_array<mesh::points_2d_t>(Primitive, trim_point_structure, "points");
		mesh::selection_t& point_selections = require_array<mesh::selection_t>(Primitive, trim_point_structure, "point_selections");

		require_metadata(Primitive, patch_selections, "patch_selections", metadata::key::role(), metadata::value::selection_role());
		require_metadata(Primitive, patch_points, "patch_points", metadata::key::domain(), metadata::value::mesh_point_indices_domain());

		require_table_row_count(Primitive, u_knot_structure, "u_knot",
			std::accumulate(patch_u_point_counts.begin(), patch_u_point_counts.end(), 0)
			+ std::accumulate(patch_u_orders.begin(), patch_u_orders.end(), 0));
		require_table_row_count(Primitive, v_knot_structure, "v_knot",
			std::accumulate(patch_v_point_counts.begin(), patch_v_point_counts.end(), 0)
			+ std::accumulate(patch_v_orders.begin(), patch_v_orders.end(), 0));

		require_table_row_count(Primitive, constant_attributes, "constant", 1);
		require_table_row_count(Primitive, uniform_attributes, "uniform", uniform_structure.row_count());
		/** \todo Compute the varying attribute size */
		//require_table_row_count(Primitive, varying_attributes, "varying", );
		require_table_row_count(Primitive, vertex_attributes, "vertex", vertex_structure.row_count());

	return new primitive(
		patch_first_points,
		patch_u_point_counts,
		patch_v_point_counts,
		patch_u_orders,
		patch_v_orders,
		patch_u_first_knots,
		patch_v_first_knots,
		patch_selections,
		patch_materials,
		patch_points,
		patch_point_weights,
		patch_u_knots,
		patch_v_knots,
		patch_first_trim_loops,
		patch_trim_loop_counts,
		trim_loop_first_curves,
		trim_loop_curve_counts,
		trim_loop_selections,
		curve_first_points,
		curve_point_counts,
		curve_orders,
		curve_first_knots,
		curve_selections,
		curve_points,
		curve_point_weights,
		curve_knots,
		points,
		point_selections,
		constant_attributes,
		uniform_attributes,
		varying_attributes,
		vertex_attributes);
	}
	catch(std::exception& e)
	{
		log() << error << e.what() << std::endl;
	}

	return 0;
}

primitive* validate(pipeline_data<mesh::primitive>& Primitive)
{
  if(!Primitive.get())
    return 0;

	if(Primitive->type != "nurbs_patch")
		return 0;

  return validate(Primitive.writable());
}

} // namespace nurbs_patch

} // namespace k3d

