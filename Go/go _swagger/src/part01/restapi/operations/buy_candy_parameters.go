// Code generated by go-swagger; DO NOT EDIT.

package operations

// This file was generated by the swagger tool.
// Editing this file might prove futile when you re-run the swagger generate command

import (
	"net/http"

	"github.com/go-openapi/errors"
	"github.com/go-openapi/runtime"
	"github.com/go-openapi/runtime/middleware"
	"github.com/go-openapi/validate"
)

// NewBuyCandyParams creates a new BuyCandyParams object
//
// There are no default values defined in the spec.
func NewBuyCandyParams() BuyCandyParams {

	return BuyCandyParams{}
}

// BuyCandyParams contains all the bound params for the buy candy operation
// typically these are obtained from a http.Request
//
// swagger:parameters buyCandy
type BuyCandyParams struct {

	// HTTP Request Object
	HTTPRequest *http.Request `json:"-"`

	/*summary of the candy order
	  In: body
	*/
	Order BuyCandyBody
}

// BindRequest both binds and validates a request, it assumes that complex things implement a Validatable(strfmt.Registry) error interface
// for simple values it will use straight method calls.
//
// To ensure default values, the struct must have been initialized with NewBuyCandyParams() beforehand.
func (o *BuyCandyParams) BindRequest(r *http.Request, route *middleware.MatchedRoute) error {
	var res []error

	o.HTTPRequest = r

	if runtime.HasBody(r) {
		defer r.Body.Close()
		var body BuyCandyBody
		if err := route.Consumer.Consume(r.Body, &body); err != nil {
			res = append(res, errors.NewParseError("order", "body", "", err))
		} else {
			// validate body object
			if err := body.Validate(route.Formats); err != nil {
				res = append(res, err)
			}

			ctx := validate.WithOperationRequest(r.Context())
			if err := body.ContextValidate(ctx, route.Formats); err != nil {
				res = append(res, err)
			}

			if len(res) == 0 {
				o.Order = body
			}
		}
	}
	if len(res) > 0 {
		return errors.CompositeValidationError(res...)
	}
	return nil
}
