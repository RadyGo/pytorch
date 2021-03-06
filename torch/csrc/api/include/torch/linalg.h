#pragma once

#include <ATen/ATen.h>

namespace torch {
namespace linalg {

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace detail {

inline Tensor cholesky(const Tensor& self) {
  return torch::linalg_cholesky(self);
}

inline Tensor cholesky_out(Tensor& result, const Tensor& self) {
  return torch::linalg_cholesky_out(result, self);
}

inline Tensor det(const Tensor& self) {
  return torch::linalg_det(self);
}

inline Tensor norm(const Tensor& self, optional<Scalar> opt_ord, optional<IntArrayRef> opt_dim, bool keepdim, optional<ScalarType> opt_dtype) {
  return torch::linalg_norm(self, opt_ord, opt_dim, keepdim, opt_dtype);
}

inline Tensor norm(const Tensor& self, std::string ord, optional<IntArrayRef> opt_dim, bool keepdim, optional<ScalarType> opt_dtype) {
  return torch::linalg_norm(self, ord, opt_dim, keepdim, opt_dtype);
}

inline Tensor& norm_out(Tensor& result, const Tensor& self, optional<Scalar> opt_ord, optional<IntArrayRef> opt_dim, bool keepdim, optional<ScalarType> opt_dtype) {
  return torch::linalg_norm_out(result, self, opt_ord, opt_dim, keepdim, opt_dtype);
}

inline Tensor& norm_out(Tensor& result, const Tensor& self, std::string ord, optional<IntArrayRef> opt_dim, bool keepdim, optional<ScalarType> opt_dtype) {
  return torch::linalg_norm_out(result, self, ord, opt_dim, keepdim, opt_dtype);
}

inline Tensor tensorinv(const Tensor& self, int64_t ind) {
  return torch::linalg_tensorinv(self, ind);
}

inline Tensor& tensorinv_out(Tensor& result,const Tensor& self, int64_t ind) {
  return torch::linalg_tensorinv_out(result, self, ind);
}

inline Tensor tensorsolve(const Tensor& self, const Tensor& other, optional<IntArrayRef> dims) {
  return torch::linalg_tensorsolve(self, other, dims);
}

inline Tensor& tensorsolve_out(Tensor& result, const Tensor& self, const Tensor& other, optional<IntArrayRef> dims) {
  return torch::linalg_tensorsolve_out(result, self, other, dims);
}

} // namespace detail
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/// Cholesky decomposition
///
/// See https://pytorch.org/docs/master/linalg.html#torch.linalg.cholesky
///
/// Example:
/// ```
/// auto A = torch::randn({4, 4});
/// auto A = torch::matmul(A, A.t());
/// auto L = torch::linalg::cholesky(A);
/// assert(torch::allclose(torch::matmul(L, L.t()), A));
/// ```
inline Tensor cholesky(const Tensor& self) {
  return detail::cholesky(self);
}

inline Tensor cholesky_out(Tensor& result, const Tensor& self) {
  return detail::cholesky_out(result, self);
}

/// See the documentation of torch.linalg.det
inline Tensor linalg_det(const Tensor& self) {
  return detail::det(self);
}

inline Tensor linalg_norm(const Tensor& self, optional<Scalar> opt_ord, optional<IntArrayRef> opt_dim, bool keepdim, optional<ScalarType> opt_dtype) {
  return detail::norm(self, opt_ord, opt_dim, keepdim, opt_dtype);
}

inline Tensor linalg_norm(const Tensor& self, std::string ord, optional<IntArrayRef> opt_dim, bool keepdim, optional<ScalarType> opt_dtype) {
  return detail::norm(self, ord, opt_dim, keepdim, opt_dtype);
}

inline Tensor& linalg_norm_out(Tensor& result, const Tensor& self, optional<Scalar> opt_ord, optional<IntArrayRef> opt_dim, bool keepdim, optional<ScalarType> opt_dtype) {
  return detail::norm_out(result, self, opt_ord, opt_dim, keepdim, opt_dtype);
}

inline Tensor& linalg_norm_out(Tensor& result, const Tensor& self, std::string ord, optional<IntArrayRef> opt_dim, bool keepdim, optional<ScalarType> opt_dtype) {
  return detail::norm_out(result, self, ord, opt_dim, keepdim, opt_dtype);
}

/// Computes the inverse of a tensor
///
/// See https://pytorch.org/docs/master/linalg.html#torch.linalg.tensorinv
///
/// Example:
/// ```
/// auto a = torch::eye(4*6).reshape({4, 6, 8, 3});
/// int64_t ind = 2;
/// auto ainv = torch::linalg::tensorinv(a, ind);
/// ```
inline Tensor tensorinv(const Tensor& self, int64_t ind) {
  return detail::tensorinv(self, ind);
}

inline Tensor& tensorinv_out(Tensor& result, const Tensor& self, int64_t ind) {
  return detail::tensorinv_out(result, self, ind);
}

/// Computes a tensor `x` such that `tensordot(input, x, dims=x.dim()) = other`.
///
/// See https://pytorch.org/docs/master/linalg.html#torch.linalg.tensorsolve
///
/// Example:
/// ```
/// auto a = torch::eye(2*3*4).reshape({2*3, 4, 2, 3, 4});
/// auto b = torch::randn(2*3, 4);
/// auto x = torch::linalg::tensorsolve(a, b);
/// ```
inline Tensor tensorsolve(const Tensor& input, const Tensor& other, optional<IntArrayRef> dims) {
  return detail::tensorsolve(input, other, dims);
}

inline Tensor& tensorsolve_out(Tensor& result, const Tensor& input, const Tensor& other, optional<IntArrayRef> dims) {
  return detail::tensorsolve_out(result, input, other, dims);
}

}} // torch::linalg
